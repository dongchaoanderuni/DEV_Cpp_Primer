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

    for(INT index = 0; index < size; index++)
    {
        iArr[index] = index;
    }

    VECTOR<INT> iVec(begin(iArr), end(iArr));

    for(auto value:iVec)
    {
        COUT << value << ' ';
    }
    COUT << ENDL;

    return 0;
}