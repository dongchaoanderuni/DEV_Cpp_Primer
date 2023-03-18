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

void showElement(vector<string> vStr)
{
    for(auto ele:vStr)
    {
        cout << ele << " ";
    }
    cout << endl;
}

void elimDups()
{
    string input;
    vector<string> vStr;

    while(cin >> input)
    {
        vStr.push_back(input);
    }

    showElement(vStr);

    sort(vStr.begin(), vStr.end());
    showElement(vStr);

    unique(vStr.begin(), vStr.end());
    showElement(vStr);
}

int main(int argc, char* argv[])
{
    elimDups();
}
