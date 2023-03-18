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
    list<int> listInt;
    forward_list<int > fListInt;
    
    listInt.assign(vi.begin(), vi.end());
    fListInt.assign(vi.begin(), vi.end());

    auto iter = vi.begin();
    
    while(iter != vi.end())
    {
        if(*iter&1)
        {
            iter = vi.insert(iter,*iter);
            iter += 2;
        }   
        else
        {
            iter = vi.erase(iter);
        }
    }

    for(auto ele:vi)
    {
        cout << ele << " ";
    }
    cout << endl;

    auto iterList   = listInt.begin();
    while(iterList != listInt.end())
    {
        if(*iterList &1)
        {
            // ++iterList;
            iterList = listInt.insert(iterList, *iterList);
            ++iterList;
            ++iterList;
        }
        else
        {
            iterList = listInt.erase(iterList);
        }
    }

    for(auto ele:listInt)
    {
        cout << ele << " ";
    }
    cout << endl;

    auto curr   = fListInt.begin();
    auto prevfList  = fListInt.before_begin();
    while(curr != fListInt.end())
    {
        if(*curr &1)
        {
            // ++iterList;
            fListInt.insert_after(prevfList, *curr);
            prevfList = curr;
            ++curr;
        }
        else
        {
            curr = fListInt.erase_after(prevfList);   
        }
    }

    for(auto ele:fListInt)
    {
        cout << ele << " ";
    }
    cout << endl;




    return 0;
}
