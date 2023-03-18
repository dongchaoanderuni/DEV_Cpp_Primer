#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;


int funcAbs(int input)
{
    if(0 <= input)
    {
        return input;
    }
    else
    {
        return -input;
    }
}

int main()
{
    int factInput{0};

    while(cin >> factInput)
    {
        cout << "Absolute Value of " << factInput << " :" << funcAbs(factInput) << endl;
    }

    return 0;
}