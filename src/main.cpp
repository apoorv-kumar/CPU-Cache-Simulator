/*

PROTECTED BY CREATIVE COMMONS SHARE ALIKE LICENCE - 
http://creativecommons.org/licenses/by-sa/3.0/

DO NOT REMOVE THIS COMMENT (unless you are copying the code for some academic project ;)

created by - apoorv kumar
iit guwahati
apoorv.kumar247@gmail.com

do visit my blog for more codes and computer stuff- 
http://eat-sleep-code.blogspot.com/

*/


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "trace.h"
#include "config.h"
#include "cache.h"
using namespace std;

int main()
{
    char filename[30] , config_file[30] ;
    vector<Configuration> config_set;


    //get user inputs
    cout << "WELCOME TO CACHE-SIM: A BASIC CACHE SIMULATOR\n" << endl;
    cout << "MADE BY :: APOORV KUMAR\n";
    cout << "please enter the cache trace filename:: ";
    cin >> filename;
    cout << "please enter the config list filename:: ";
    cin >> config_file;


    cout << "running simulation ... please wait ... \n";
    //create trace data
    Trace mem_trace(filename);

    //create config set
    fstream config_fs(config_file);

    string temp_str;
    istringstream temp_stream(istringstream::in);
    while(getline(config_fs , temp_str))
    {
        Configuration temp_config;
        if(temp_str[0] != '#' && temp_str != "")
        {
            temp_stream.str(temp_str);
            temp_stream >> temp_config.assoc >> temp_config.cache_hit_time >> temp_config.line_size >> temp_config.replace_policy >> temp_config.set_count >> temp_config.write_policy ;
            config_set.push_back(temp_config);
        }
    }

    ofstream output_fs("output");

    int writes = 0;
    int reads = 0;

    for(int i = 0 ; i < config_set.size() ; i++)
    {
        output_fs << " ---------------------------------------------- \n";
        Cache my_cache(config_set[i]);
        writes = 0 ; reads = 0;

        for(int i = 0 ; i < mem_trace.trace_list.size(); i++)
        {
            if(mem_trace.trace_list[i].type == 'R') reads++;
            else writes++;
            my_cache.request(mem_trace.trace_list[i].address);
        }



        my_cache.print_records(output_fs);
        output_fs << " ---------------------------------------------- \n\n\n";
    }

    output_fs << "trace details -" <<endl;
    output_fs << "reads - " << reads << "  writes - " << writes << endl << endl;

    cout << "simulation complete. please check the output file.\n";

    return 0;
}
