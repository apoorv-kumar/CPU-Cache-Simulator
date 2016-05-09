#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Mem_access
{
    public:
    int address;
    char type;

    Mem_access();
    Mem_access(int address , char type);


};

class Trace
{
    public:
    Trace(char* filename);
    vector<Mem_access> trace_list;
    void print();

};
