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

int main(int argc, char* argv[])
{
    string inputStr;
    vector<string> vecStrEins;
    vector<string> vecStrZwei;


    if(2 != argc)
    {
        cout << __LINE__ << " input params not legal " << argc << endl;
        return -1;
    }

    ifstream in(argv[1]);

    while(in>>inputStr)
    {
        vecStrEins.push_back(inputStr);
    }

    showElement(vecStrEins);
    stable_sort(vecStrEins.begin(),vecStrEins.end());
    unique_copy(vecStrEins.begin(),vecStrEins.end(), back_inserter(vecStrZwei));

    for(auto ele:vecStrZwei)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
