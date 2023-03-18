#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <vector>
#include <string>
#include <list>
#include <deque>
// #include "Sales_data.h"
#include "Variable.h"

using namespace std;

int main(int argc, char* argv[])
{
    vector<int> vecInt;
    list<int> listInt;

    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

    for(auto ele:ia)
    {
        vecInt.push_back(ele);
        listInt.push_back(ele);
    }

    list<int>::iterator listIt = listInt.begin();
    vector<int>::iterator vecIt = vecInt.begin();

    for(;vecInt.end() !=  vecIt;)
    {
        if(*vecIt&1)
        {
            listIt = listInt.erase(listIt);
            ++vecIt;
        }
        else
        {
            vecIt = vecInt.erase(vecIt);
            ++listIt;
        }
    }


    for(auto ele:listInt)
    {
        cout << ele << " ";
    }
    cout << endl;


    for(auto ele:vecInt)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
