#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;


int fact(int input)
{
    int returnValue{1};

    while(1 < input)
    {
        returnValue *= input--;
    }

    return returnValue;
}

int main()
{
    int factInput{0};

    while(cin >> factInput)
    {
        cout << "FactValue of " << factInput << " :" << fact(factInput) << endl;
    }

    return 0;
}