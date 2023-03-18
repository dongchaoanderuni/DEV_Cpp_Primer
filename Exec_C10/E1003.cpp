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
// #include "Sales_data.h"
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

    cout << "Sum: "<< accumulate(vInt.begin(), vInt.end(),0) << endl;

    return 0;
}
