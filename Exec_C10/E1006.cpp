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


int main(int argc, char* argv[])
{
    int input;
    vector<int> vInt;

    while(cin>>input)
    {
        vInt.push_back(input);
    }

    fill_n(vInt.begin(),vInt.size(),0);

    for(auto ele:vInt)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
