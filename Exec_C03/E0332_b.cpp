#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"

using namespace std;

int main()
{
    CONST INT totalLength = 10;
    VECTOR<INT> vectEins;
    VECTOR<INT> vectZwei;

    for(INT index = 0; index < totalLength; index++)
    {
        vectEins.push_back(index);
    }    

    for(auto it:vectEins)
    {
        COUT << it << ' ';
    }
    COUT << ENDL;

    for(auto it:vectEins)
    {
        vectZwei.push_back(it);
    }

    for(auto it:vectZwei)
    {
        COUT << it << ' ';
    }
    COUT << ENDL;

    return 0;
}