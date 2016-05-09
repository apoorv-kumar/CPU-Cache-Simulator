#include "cache_set.h"
#include <iostream>

bool Cache_set::process_word(int word_address)
{
    int tag = (word_address/sizeof(int)/line_size);
    bool search_result = find_tag(tag); // the data structs updated in this fn itself incase found

    if(search_result == false) insert_element(tag);

    return search_result;

}

Cache_set:: Cache_set(int ln_size , int associativity , int replace_pol)
{
    assoc = associativity;
    line_size = ln_size;
    replacement_policy = replace_pol;

    //create lines and push into set
    Cache_line temp(line_size);
    cache_set_lines.assign(associativity , temp);
}

int Cache_set::evict()
{
    for(int i = 0 ; i < assoc ; i++)
    {
        if(!cache_set_lines[i].dirty_bit) cerr << "EMPTY LINE PRESENT AND still EVICTION CALLED... PLEASE CHECK ALGO\n";
    }

    if(replacement_policy  == REPLACEMENT_RANDOM)
    {
        return (rand()%assoc) ; // return random index
    }
    else if(replacement_policy == REPLACEMENT_LRU)
    {
        //record and delete last element
        int del_index = LRU_list.back();
        LRU_list.pop_back();
        //return the element index
        //if(del_index <0 || del_index >= assoc) std::cerr << "erroreneous index : " <<  del_index << endl;
        return del_index;
    }
    else if(replacement_policy == REPLACEMENT_FIFO)
    {
        //see and pop the front element of queue
        int del_index  = FIFO_list.front();
        FIFO_list.pop();
        //return the element index
        return del_index;
    }
    else
    {
        cerr << "replacement policy" << replacement_policy << " not recognized ...\n";
        return 0;
    }
}

bool Cache_set:: find_tag(int search_tag)
{

    for(int index = 0 ; index < assoc ; index++)
    {
        if(cache_set_lines[index].dirty_bit || 1)
        {

            if(cache_set_lines[index].find_word(search_tag) )
            {

                //update the access data structs
                if(replacement_policy == REPLACEMENT_LRU)
                {
                    LRU_list.remove(index);// remove
                    LRU_list.push_front(index); // and place at front
                }

                return true;
            }
        }

    }
    return false;
}

void Cache_set::insert_element(int insert_tag)
{
    bool no_dirty_bit = true;

    if(find_tag(insert_tag))
    //if tag already present
    {
        cerr << "the tag inserted is already in memory - please check the algo\n";
    }
    else
    {
        //search for empty lines
        for(int i = 0 ; i < assoc ; i++)
        {
            if(!cache_set_lines[i].dirty_bit)
            {

                cache_set_lines[i].dirty_bit = true; // assures that gradually all will be valid
                no_dirty_bit = false;
                //insert the tag
                cache_set_lines[i].tag = insert_tag;
                //update data structs
                if(replacement_policy == REPLACEMENT_LRU)
                {
                    LRU_list.push_front(i); // place at front
                }
                else if (replacement_policy == REPLACEMENT_FIFO)
                {
                    FIFO_list.push(i);
                }
                break;
            }
        }

        //incase no empty lines ... evict as per algo.
        if(no_dirty_bit)
        {
            //evict and get the evicted index
            int del_index = evict();
            //if (del_index > assoc) cout << "error here : del_index = "
            //insert the new line
            cache_set_lines[del_index].tag = insert_tag;
            //refresh the data structs
            if (replacement_policy == REPLACEMENT_LRU)
            {
                //put the element at the front
                LRU_list.push_front(del_index);
            }
            else if(replacement_policy == REPLACEMENT_FIFO)
            {
                //put the element at end
                FIFO_list.push(del_index);
            }
        }
    }
}
