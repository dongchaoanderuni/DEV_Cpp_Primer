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
// #include "Sales_data.h"
#include "Variable.h"

using namespace std;


int main(int argc, char* argv[])
{
    int input;
    vector<int> vInt;
    int countValue{0};

    while(cin>>input)
    {
        vInt.push_back(input);
    }

    cout << "Please input the target Value you want to find." << endl;

    cin >> input;

    cout << "TargetValue: " << input  << " : "<< count(vInt.begin(), vInt.end(),input) << " times." << endl;

    return 0;
}
