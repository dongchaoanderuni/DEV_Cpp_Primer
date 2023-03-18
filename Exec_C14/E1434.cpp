#include <iostream>
#include "SelfFunction.h"

using namespace std;

int main()
{
    SELFFUNCTION ite;
    cout << ite(true, 10, 20) << endl; // Output: 10
    cout << ite(false, 10, 20) << endl; // Output: 20

    return 0;
}
