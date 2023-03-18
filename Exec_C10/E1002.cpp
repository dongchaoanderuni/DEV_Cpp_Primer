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
    string input;
    vector<string> vInt;
    string countValue;

    while(cin>>input)
    {
        vInt.push_back(input);
    }

    cout << "Please input the target String you want to find." << endl;

    cin >> input;

    cout << "TargetString: " << input  << " : "<< count(vInt.begin(), vInt.end(),input) << " times." << endl;

    return 0;
}
