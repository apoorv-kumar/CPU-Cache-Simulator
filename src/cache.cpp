#include "cache.h"
#include <iostream>

Cache::Cache(const Configuration& config)
{
    cache_config = config;
    misses = 0;
    hits = 0;
    total_accesses = 0;

    //init cache sets
    Cache_set temp_cache_set(cache_config.line_size , cache_config.assoc , config.replace_policy);
    cache_sets.assign(config.set_count , temp_cache_set);
}

Cache::Cache()
{
    cache_config = *(new Configuration);
    misses = 0;
    hits = 0;
    total_accesses = 0;

    //init cache sets
    Cache_set temp(cache_config.line_size , cache_config.assoc , cache_config.replace_policy);
    cache_sets.assign(cache_config.set_count , temp);

}

void Cache:: request(int memory_address)
{
    int cache_set_id = (memory_address/sizeof(int)/cache_config.line_size)%cache_config.set_count;
    if(cache_sets[cache_set_id].process_word(memory_address))
    {
        hits++;
        total_accesses++;
    }
    else
    {
        misses++;
        total_accesses++;
    }
}


void Cache::print_records()
{
    std::cout << "running config::\n";
    cache_config.print();
    cout << "results:: " << endl;
    std::cout << "hits :: " << hits << endl;
    std::cout << "misses :: " << misses << endl;
}

void Cache::print_records(ofstream& ofs)
{
    ofs << "running config::\n";
    cache_config.print(ofs);
    ofs << endl << "results:: " << endl;
    ofs << "hits :: " << hits << endl;
    ofs << "misses :: " << misses << endl << endl;
}
