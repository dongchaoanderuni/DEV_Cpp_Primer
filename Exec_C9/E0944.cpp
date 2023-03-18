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
    int p = 0;
    while(((p = s.find(oldVal, p)))&& 
           (p != string::npos))
    {
        s.replace(p, oldVal.size(), newVal);
        p += newVal.size();
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
