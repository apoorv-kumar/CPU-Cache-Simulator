#include "cache_line.h"
#include <iostream>

Cache_line:: Cache_line(int ln_size)
{
    line_size = ln_size;

    //this is inconsequential
    //line_data.assign(line_size , 0);

    dirty_bit = 0;
}

bool Cache_line::find_word(int word_tag)
{
    //chk if word lies in range
    if(word_tag == tag )
    {
        return true;
    }
    else
    {
        return false;
    }

}
