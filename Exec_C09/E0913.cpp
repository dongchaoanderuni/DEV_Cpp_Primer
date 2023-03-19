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
    list<int> listInt{0,1,2,3,4,5,6,7,8,9};
    vector<int> vectIntZwei = {0,1,2,3,4,5,6,7,8,9};

    vector<double> vecDouble(listInt.begin(), listInt.end());
    vector<double> vecDoubleZwei(vectIntZwei.begin(), vectIntZwei.end());


    cout << __LINE__ << endl;
    for(auto ele:vecDouble)
    {
        cout << ele << " ";
    }
    cout << "\n" << endl;


    cout << __LINE__ << endl;
    for(auto ele:vecDoubleZwei)
    {
        cout << ele << " ";
    }
    cout << "\n" << endl;


    return 0;
}
