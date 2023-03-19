#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
// #include "Sales_data.h"
#include "Variable.h"

using namespace std;

int main(int argc, char* argv[])
{
    forward_list<int> fListInt = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

    forward_list<int>::iterator curr = fListInt.begin();
    forward_list<int>::iterator prev = fListInt.before_begin();

    for(;fListInt.end() != curr;)
    {
        if(*curr&1)
        {
            curr = fListInt.erase_after(prev);
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }

    for(auto ele:fListInt)
    {
        cout << ele << " ";
    }
    cout << endl;




    return 0;
}
