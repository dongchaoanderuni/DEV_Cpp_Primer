#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
#include "Variable.h"

using namespace std;

int main()
{
    vector<string> v1;
    string String;

    while(cin>>String)
    {
        for(auto &r:String)
        {
            r = toupper(r);
        }
        cout << String << endl;
    }

    return 0;

}