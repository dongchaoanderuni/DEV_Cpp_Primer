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

void showElement(list<int> &vStr)
{
    for(auto ele:vStr)
    {
        cout << ele << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    int inputInt;
    vector<int> vecInt;
    list<int> vecIntEins;
    list<int> vecIntZwei;
    list<int> vecIntDrei;

    if(2 != argc)
    {
        cout << __LINE__ << " input params not legal " << argc << endl;
        return -1;
    }

    ifstream in(argv[1]);

    while(in>>inputInt)
    {
        vecInt.push_back(inputInt);
    }
    showElement(vecInt);

    copy(vecInt.begin(), vecInt.end(), back_inserter(vecIntEins));
    cout << "back_inserter: " << endl;
    showElement(vecIntEins);

    copy(vecInt.begin(), vecInt.end(), front_inserter(vecIntZwei));
    cout << "front_inserter: " << endl;
    showElement(vecIntZwei);

    copy(vecInt.begin(), vecInt.end(), inserter(vecIntDrei, vecIntDrei.begin()));
    cout << "inserter: " << endl;
    showElement(vecIntDrei);


    return 0;
}
