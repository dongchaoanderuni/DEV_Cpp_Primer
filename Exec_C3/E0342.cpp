#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string.h>

using namespace std;

int main()
{
    CONSTEXPR SIZE_T size = 10;
    INT iArr[size];
    INT *p = iArr;
    VECTOR<INT> iVec;

    for(INT index = 0; index < size; index++)
    {
        iVec.push_back(index);
    }


    for(auto value:iVec)
    {
        *p = value;
        p++;
    }


    for(auto value:iArr)
    {
        COUT << value << ' ';
    }
    COUT << ENDL;



    return 0;
}