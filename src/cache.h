#include "config.h"
#include "cache_set.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <queue>
#include <map>

using namespace std;

class Cache
{
    //PARAMS
    Configuration cache_config;

    //records
    int misses;
    int hits;
    int total_accesses;

    //data
    vector<Cache_set> cache_sets;


    public:
    //constr
    Cache(const Configuration&);
    Cache();

    //access methods
    void request(int memory_address); // in ideal sim , should reply with some data ...

    //print
    void print_records();
    void print_records(ofstream&);

};


