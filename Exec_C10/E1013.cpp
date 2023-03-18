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

    sort(vStr.begin(), vStr.end(), isShorter);
    showElement(vStr);

    stable_sort(vStr.begin(), vStr.end(), isShorter);
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

int main(int argc, char* argv[])
{
    string input;
    vector<string> vStr;

    while(cin >> input)
    {
        vStr.push_back(input);
    }
    showElement(vStr);

    divide(vStr);
}
