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
    list<int> listInt = {0,1,2,3,4,5,6,7,8,9};
    deque<int> dequeIntEven = {};
    deque<int> dequeIntOdd  = {};

    for(auto ele:listInt)
    {
        if(ele&1)
        {
            dequeIntEven.push_back(ele);
        }
        else
        {
            dequeIntOdd.push_back(ele);
        }
    }

    for(auto ele:dequeIntEven)
    {
        cout << ele << " ";
    }
    cout << endl;


    for(auto ele:dequeIntOdd)
    {
        cout << ele << " ";
    }
    cout << endl;

}
