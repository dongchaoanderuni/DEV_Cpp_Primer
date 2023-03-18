#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <vector>
#include <string>
#include <list>
#include <deque>
// #include "Sales_data.h"
#include "Variable.h"

using namespace std;

int main(int argc, char* argv[])
{
    deque<string> dequeStr;
    string input;

    if(2 != argc)
    {
        cout << __LINE__ << " input params not legal " << argc << endl;
        return -1;
    }

    ifstream in(argv[1]);

    while(in>>input)
    {
        dequeStr.push_back(input);
    }

    for(auto ele:dequeStr)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
