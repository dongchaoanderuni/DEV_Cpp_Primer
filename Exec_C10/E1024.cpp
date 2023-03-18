#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include "Variable.h"

using namespace std;

void showElement(vector<string> &vStr)
{
    for(auto ele:vStr)
    {
        cout << ele << " ";
    }
    cout << endl;
}

void showElement(vector<int> &vStr)
{
    for(auto ele:vStr)
    {
        cout << ele << " ";
    }
    cout << endl;
}


bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void elimDups(vector<string> vStr)
{
    sort(vStr.begin(), vStr.end());
    showElement(vStr);

    auto end_unique = unique(vStr.begin(), vStr.end());
    vStr.erase(end_unique, vStr.end());
    showElement(vStr);
}

bool isShorterThenTargetValue(const string &s1)
{
    return s1.size() >= 5;
}

void divide(vector<string> &vStr)
{
    elimDups(vStr);

    auto partVecStr = partition(vStr.begin(), vStr.end(), isShorterThenTargetValue);
    vStr.erase(partVecStr, vStr.end());
    showElement(vStr);
}

bool check_size(const string &s1, string::size_type sz)
{
    return s1.size() < sz;
}

void countNumbers(vector<int> &vInt, string &str)
{ 
    /* 打印长度大于给定值得单词，每个单词后面接一个空格 */

    cout << *find_if(vInt.begin(), vInt.end(),
                    bind(check_size, str, placeholders::_1))<<  endl;
}



int main(int argc, char* argv[])
{
    int input;
    string inputStr;
    vector<int> vectInt;


    if(3 != argc)
    {
        cout << __LINE__ << " input params not legal " << argc << endl;
        return -1;
    }

    ifstream in(argv[1]);

    while(in>>input)
    {
        vectInt.push_back(input);
    }

    inputStr = argv[2] ;

    showElement(vectInt);

    countNumbers(vectInt, inputStr);



}
