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


void sumOfZweiEles(vector<int> &vInt)
{
    auto sumAandB =[vInt](int a, int b){return a+b;};
    cout <<  sumAandB(vInt[0],vInt[1]) << endl;

    return;
}

void sumOfEinsElem(vector<int> &vInt)
{
    auto sumAandB =[](int a){return a+5;};
    for(auto ele:vInt)
    {
        cout << sumAandB(ele)<<" ";
    }
    cout << endl;

    return;
}

int main()
{
    int input;
    vector<int> vInt;

    while(cin >> input)
    {
        vInt.push_back(input);
    }
    showElement(vInt);
    sumOfEinsElem(vInt);

}
