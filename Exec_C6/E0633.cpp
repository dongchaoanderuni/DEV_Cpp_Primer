#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

int factWithRecursive(int val)
{
    if(val > 1)
    {
        return val * factWithRecursive(val-1);
    }
    return 1;
}


int main()
{
    int input{0};
    while(cin >> input)
    {
        cout << "fact of " << input  << " :\t" << factWithRecursive(input) << endl;
        // cout << "fact of " << input  << endl;
    }

    return 0;
}
