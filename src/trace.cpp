#include "trace.h"
#include <iostream>
using namespace std;

Mem_access::Mem_access(int ad , char t)
{
     address = ad;
     type = t;
}

Trace::Trace(char* filename)
{
    fstream trace_file_stream;
    trace_file_stream.open(filename);

    if(!trace_file_stream.is_open()) cerr << " COULDN'T OPEN FILE " << filename << " :(";

    int addr;
    char tp;

    while(trace_file_stream >> addr >> tp )
    {
        Mem_access temp(addr , tp);
        trace_list.push_back(temp);
    }
}

void Trace:: print()
{
    cout << trace_list.size() << endl;
//    for (int i = 0 ; i < trace_list.size() ; i++)
//    {
//        cout << trace_list[i].type << "  -  " << trace_list[i].address << endl;
//    }
}
