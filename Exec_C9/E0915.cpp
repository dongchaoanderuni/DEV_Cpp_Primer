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
    vector<int> vecIntEins{0,1,2,3,4,5,6,7,8,9};
    vector<int> vecIntZwei{0,1,2,3,4,5,6,7,8,9,10};
    vector<int> vectIntDrei{0};
    vector<int> vectIntVier(vecIntEins);

    list<int> listInt(vecIntEins.begin(),vecIntEins.end());


    // if(vecIntEins == vectIntVier)
    // {
    //     cout << "True" << endl;
    // }


    if(listInt.size() == vecIntEins.size())
    {
        auto listBegin  = listInt.begin();
        auto listEnd    = listInt.end();

        auto vecBegin   = vecIntEins.begin();
        auto vecEnd     = vecIntEins.end();
        
        for(;vecBegin != vecEnd;++listBegin,++vecBegin)
        {
            if(*listBegin != *vecBegin)
            {
                cout << "False" << endl;
            }

        }
        cout << "True" << endl;
    }


    return 0;
}
