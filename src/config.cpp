#include "config.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

    static const int REPLACEMENT_RANDOM = 1;
    static const int REPLACEMENT_LRU = 2;
    static const int REPLACEMENT_FIFO = 3;


    static const int WRITE_THROUGH = 1;
    static const int WRITE_BACK = 2;

Configuration::Configuration()
{
    //default settings
    assoc = 10;
    cache_hit_time = 5;
    cache_miss_penalty = 50;
    line_size = 2048;
    replace_policy = REPLACEMENT_FIFO;
    set_count = 4096; // 1K x 8 x 4 BYTES = 32K Cache
    write_policy =  WRITE_BACK;
}

//read a file and set params
//Configuration:: Configuration(char* filename)
//{
//    fstream config_file(filename);
//
//
//}

void Configuration::print()
{
    string policy;
    switch(replace_policy)
    {
        case REPLACEMENT_FIFO : policy = "FIFO"; break;
        case REPLACEMENT_LRU : policy = "LRU"; break;
        case REPLACEMENT_RANDOM : policy = "RANDOM"; break;
        default : policy = "INVALID";
    }

    cout << "associativity = " << assoc << endl;
    cout << "line size = " << line_size << endl;
    cout << "replacement_policy = " << policy << endl;
    cout << "set count = " << set_count << endl;
    cout << "write policy = " << "WRITE BACK" << endl;
}


void Configuration::print(ofstream& ofs)
{
    string policy;
    switch(replace_policy)
    {
        case REPLACEMENT_FIFO : policy = "FIFO"; break;
        case REPLACEMENT_LRU : policy = "LRU"; break;
        case REPLACEMENT_RANDOM : policy = "RANDOM"; break;
        default : policy = "INVALID";
    }

    ofs << "associativity = " << assoc << endl;
    ofs << "line size = " << line_size << endl;
    ofs << "replacement_policy = " << policy << endl;
    ofs << "set count = " << set_count << endl;
    ofs << "write policy = " << "WRITE BACK" << endl;
}

