#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <vector>
#include <string>
#include <list>
// #include "Sales_data.h"
#include "Variable.h"

using namespace std;

int main(int argc, char* argv[])
{
    list<char*> listChar={"a", "an", "the"};
    vector<string> vecStr(listChar.begin(),listChar.end());
    vector<string> vecStrZwei;

    vecStrZwei.assign(listChar.begin(), listChar.end());

    cout << __LINE__ << endl;
    for(auto ele:vecStr)
    {
        cout << ele << " ";
    }
    cout << "\n" << endl;

    cout << __LINE__ << endl;
    for(auto ele:vecStrZwei)
    {
        cout << ele << " ";
    }
    cout << "\n" << endl;

    return 0;
}
