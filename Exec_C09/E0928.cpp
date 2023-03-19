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


void insertStringBeforeTarget(forward_list<string> &fListStr, const string &targetStr, 
                                const string &insertStr)
{
    forward_list<string>::iterator curr = fListStr.begin();
    forward_list<string>::iterator prev = fListStr.before_begin();

    while(fListStr.end() != curr)
    {
        if(*curr == targetStr)
        {
            // cout << targetStr << endl;
            // cout << insertStr << endl;
            fListStr.insert_after(prev,insertStr);
            return;
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }
    if(fListStr.end() == curr)
    {
        // cout << targetStr << endl;
        // cout << insertStr << endl;
        fListStr.insert_after(prev,insertStr);
    }
    return;
}


int main(int argc, char* argv[])
{
    forward_list<string> fListInt = {"a","the", "an"};
    string input;

    if(2 != argc)
    {
        cout << __LINE__ << " input params not legal " << argc << endl;
        return -1;
    }

    ifstream in(argv[1]);
    string targetStr;
    string insertStr;

    in >> targetStr;
    in >> insertStr;


    insertStringBeforeTarget(fListInt,targetStr,insertStr);
    for(auto ele:fListInt)
    {
        cout << ele << " ";
    }
    cout << endl;

    in >> targetStr;
    in >> insertStr;

    insertStringBeforeTarget(fListInt,targetStr,insertStr);
    for(auto ele:fListInt)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
