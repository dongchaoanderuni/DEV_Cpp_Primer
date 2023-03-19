#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"

using namespace std;

int main()
{
    CONSTEXPR INT size = 10;
    INT iArray[size] = {};
    INT *pIArray = NULL;
    INT count = 0;

    for(INT index = 0; index < size; index++)
    {
        iArray[index] = index;
    }

    for(AUTO value:iArray)
    {
        COUT << value << ' ';
    }
    COUT << ENDL;


    pIArray = iArray;

    while(count < size)
    {
        *pIArray = 0;
        ++pIArray;
        ++count;
    }

    for(AUTO value:iArray)
    {
        COUT << value << ' ';
    }
    COUT << ENDL;


    return 0;
}