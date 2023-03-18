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
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    
    while(iter != vi.end())
    {
        if(*iter&1)
        {
            iter = vi.insert(iter,*iter);
            ++iter;
        }   
        ++iter;
    }

    for(auto ele:vi)
    {
        cout << ele << " ";
    }
    cout << endl;




    return 0;
}
