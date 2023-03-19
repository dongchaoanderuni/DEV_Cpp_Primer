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

void replaceStr(string &s, const string &oldVal, const string &newVal)
{
    vector<string> vecStr;

    auto iter = s.begin();
    for(;iter != s.end();)
    {
        auto iter1    = s.begin();
        auto iter2 = oldVal.begin();

        while((*iter2 == *iter1)
            &&(iter1!=oldVal.end()))
            {
                ++iter1;
                ++iter2;
            }
        if(iter2 == oldVal.end())
        {
            iter1 = s.erase(iter, iter1);
            if(newVal.size())
            {
                iter2 = newVal.end();
            }
            do
            {
                --iter2;
                iter = s.insert(iter,*iter2);
                /* code */
            } while (iter2 > newVal.begin());
            iter += newVal.size();
        }
        else
        {
            ++iter;
        }

    }



    return;
}

int main(int argc, char* argv[])
{
    string s = "ajpeaw vnk lvszn tho ap nnzvkn thru awjfpo nanv ";
    vector<string> vecStr;


    replaceStr(s, "tho", "though");

    for(auto ele:s)
    {
        cout << ele;
    }
    cout << endl;


    replaceStr(s, "thru", "through");

    for(auto ele:s)
    {
        cout << ele;
    }
    cout << endl;


    return 0;
}
