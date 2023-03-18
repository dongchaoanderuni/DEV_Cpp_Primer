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

void showElement(vector<int> &vInt)
{
    for(auto ele:vInt)
    {
        cout << ele << " ";
    }
    cout << endl;
}

void isIntlessthanZero(vector<int> &vInt)
{
    auto lessThenZero = [](int &eleInt)->bool{if(eleInt > 0) {while(--eleInt); return false;}else return true;};

    for(auto ele:vInt)
    {
        cout << ele << " ";
        cout << lessThenZero(ele) << " ";
    }
    cout << endl;

    return;
}


int main(int argc, char* argv[])
{
    int input;
    vector<int> vInt;

    while(cin >> input)
    {
        vInt.push_back(input);
    }
    showElement(vInt);

    isIntlessthanZero(vInt);

}
