#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <vector>
#include <string>
// #include "Sales_data.h"
#include "Variable.h"

using namespace std;

#define LegalInput (2)

int main(int argc, char* argv[])
{
    vector<int> vecInt;
    vector<int> vectIntZwei = {0,1,2,3,4,5,6,7,8,9};
    vector<int> vectIntDrei = {542};
    vector<int> vectIntVier(10,1);
    vector<int> vecIntFunf(10);
    vector<int> vecIntSiex(vectIntZwei);
    vector<int> vecIntSieben(vectIntZwei.begin(), vectIntZwei.end());

    cout << __LINE__ << endl;
    for(auto ele:vecInt)
    {
        cout << ele << " ";
    }
    cout << endl;

    cout << __LINE__ << endl;
    for(auto ele:vectIntZwei)
    {
        cout << ele << " ";
    }
    cout << "\n" << endl;

    cout << __LINE__ << endl;
    for(auto ele:vectIntDrei)
    {
        cout << ele << " ";
    }
    cout << "\n" << endl;

    cout << __LINE__ << endl;
    for(auto ele:vectIntVier)
    {
        cout << ele << " ";
    }
    cout << "\n" << endl;

    cout << __LINE__ << endl;
    for(auto ele:vecIntFunf)
    {
        cout << ele << " ";
    }
    cout << "\n" << endl;

    cout << __LINE__ << endl;
    for(auto ele:vecIntSiex)
    {
        cout << ele << " ";
    }
    cout << "\n" << endl;

    cout << __LINE__ << endl;
    for(auto ele:vecIntSieben)
    {
        cout << ele << " ";
    }
    cout << "\n" << endl;



    return 0;
}
