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
    int beginpos{0};
    int endpos{0};
    for(int index = 0; index < s.size(); ++index)
    {
        if((' ' == s[index+1])
            ||('\0' == s[index+1]))
        {
            endpos = index+1;
            // cout <<"index: " << index <<  " beginpos: " << beginpos << " endpos: " << endpos << " " << "endpos-beginpos: " << endpos-beginpos << " " <<s.substr(beginpos,endpos-beginpos)<< endl; 

            vecStr.push_back(s.substr(beginpos,endpos-beginpos));
            beginpos = index+2;
        }
    }


    for(auto &ele:vecStr)
    {
        if(oldVal == ele)
        {
            ele = newVal;
        }
    }

    s.erase();

    for(auto ele:vecStr)
    {
        s.insert(s.size(),ele+" ");
    }

    // s.replace(0, )

    cout << endl;




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
