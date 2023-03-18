#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"

using namespace std;

int main()
{

    CONSTEXPR SIZE_T arraySize = 10;
    INT ia[arraySize] = {};
    INT i{0};
    INT ia_Zwei[arraySize] = {};

    for(SIZE_T index = 0; index < arraySize; ++index )
    {
        ia[index] = index;
    }
    COUT << ENDL;

    for(AUTO index:ia)
    {
        COUT << index << ' ';
    }
    COUT<<ENDL;

    for(SIZE_T index = 0; index < arraySize; ++index )
    {
        ia_Zwei[index] = ia[index];
    }

    for(AUTO index:ia_Zwei)
    {
        COUT << index << ' ';
    }
    COUT<<ENDL;

    return 0;
}