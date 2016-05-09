#include "cache_line.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <queue>
#include <map>
using namespace std;

    static const int REPLACEMENT_RANDOM = 1;
    static const int REPLACEMENT_LRU = 2;
    static const int REPLACEMENT_FIFO = 3;

    static const int WRITE_THROUGH = 1;
    static const int WRITE_BACK = 2;

class Cache_set
{
    //params
    int line_size;
    int assoc;
    int replacement_policy;

    //record data for eviction
    vector<Cache_line> cache_set_lines; // array of cache lines
    list<int> LRU_list; // list maintains the record of usage
    queue<int> FIFO_list; // queue maitains record on insertion

    //internal methods
    int evict(); // returns the index of line to be overwritten ... sets up the decision datastrs
    bool find_tag(int tag);
    void insert_element(int tag);


    public:
    //constr
    Cache_set(int line_size ,int associativity , int replace_pol);

    //interface - returns if a word is present or not.
    bool process_word(int word_address);
};
