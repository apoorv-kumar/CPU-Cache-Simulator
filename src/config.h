//1. Number of sets
//2. Associativity
//3. Linesize
//4. WritePolicy(WT/WB)
//5. Replacement policy (random, lru, fifo)
//6. Cache hit time, cache miss penalty


#include <iostream>
#include <fstream>
#include <string>

#ifndef __CONFIG__
#define __CONFIG__


class Configuration
{
    public:
    int set_count;
    int assoc;
    int line_size; // in no of words. 1word = sizeof(int)
    int write_policy;
    int replace_policy;
    int cache_hit_time;
    int cache_miss_penalty;

    //constr
    Configuration(char* filename);
    Configuration();

    //print
    void print();
    void print(std::ofstream&);

};

#endif
