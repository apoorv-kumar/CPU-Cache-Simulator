#include <vector>
using namespace std;
class Cache_line
{
    public:
    //constr
    Cache_line(int line_size);
    int line_size;


    //search method
    bool find_word(int word_tag); // find word in the line

    //state and data
    int tag;
    bool dirty_bit; // tells if the line has been initialized - 0 = uninitialized

    //dummy str - not used really
    vector<int> line_data; // array of ints allocated on time of creation
};

