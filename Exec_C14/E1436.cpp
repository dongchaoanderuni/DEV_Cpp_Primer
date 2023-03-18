#include <iostream>
#include <sstream> // for istringstream
#include "ReadString.h"

using namespace std;

int main()
{
    // Test 1: Reading string from standard input
    cout << "Enter a string: ";
    ReadString rs;
    cout << "You entered: " << rs() << endl;
    vector<string> vecStr; 
    while(true)
    {   
        string line = rs();
        if(!line.empty())
        {
            vecStr.push_back(line);
        }
        break;
    }
    // // Test 2: Reading string from stringstream
    // string str = "This is a test";
    // istringstream iss(str);
    // ReadString rs2;
    // cout << "String from stringstream: " << rs2(iss) << endl;

    // // Test 3: Reading empty string from stringstream
    // string str2 = "";
    // istringstream iss2(str2);
    // ReadString rs3;
    // cout << "Empty string from stringstream: " << rs3(iss2) << endl;

    return 0;
}
