#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string.h>

using namespace std;
using int_array = int[4];

int main()
{
    cout << "Size of boolean:\t" << sizeof(bool) << endl;
    cout << "Size of char:\t" << sizeof(char) << endl;
    cout << "Size of short:\t" << sizeof(short) << endl;
    cout << "Size of int:\t" << sizeof(int) << endl;
    cout << "Size of long:\t" << sizeof(long) << endl;
    cout << "Size of long long:\t" << sizeof(long long) << endl;
    cout << "Size of float:\t" << sizeof(float) << endl;
    cout << "Size of double:\t" << sizeof(double) << endl;
    cout << "Size of long double:\t" << sizeof(long double) << endl;
    cout << "Size of ptr:\t" << sizeof(int *) << endl;
 
    return 0;
}
