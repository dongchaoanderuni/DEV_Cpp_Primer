#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string.h>

using namespace std;

int main()
{
    CONSTEXPR SIZE_T length = 35;
    CONST CHAR charArrayEins[] = "Hello World!";
    CONST CHAR charArrayZwei[] = "Servus die Welt.";
    CHAR charArrayDrei[strlen(charArrayEins) + strlen(charArrayZwei) + 1];
    COUT << strlen(charArrayEins) << ENDL;
    COUT << strlen(charArrayZwei) << ENDL;

    strcpy(charArrayDrei, charArrayEins);
    strcat(charArrayDrei, charArrayZwei);

    for(int index = 0; index < sizeof(charArrayDrei); index++)
    {
        COUT << charArrayDrei[index];
    }
    COUT << ENDL;

    return 0;
}