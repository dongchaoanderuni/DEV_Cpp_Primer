#include "Headfile.h"

using namespace std;

int main() 
{
    tuple<int, int, int> tInt{10,20,30};
    typedef decltype(tInt) typetInt;
    auto size = tuple_size<typetInt>::value;
    // for(int index = 0; index != size; index++)
    // {
    //     cout << std::get<index>(tInt) <<" ";
    // }
    cout << std::get<0>(tInt) <<" " << endl;
    cout << std::get<1>(tInt) <<" " << endl;
    cout << std::get<2>(tInt) <<" " << endl;

    return 0;
}
