#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;



size_t count_calls()
{
    static size_t ctr = 0;
    
    return ctr++;
}


void plusTwo(int iArr[])
{
    for(int index = 0; index < 10; ++index)
    {
        iArr[index] *= 2; 
    }
}



int main()
{
    int iArr[] = {0,1,2,3,4,5,6,7,8,9};
    // int *pIArr;

    // for(int index = 0; index < 10; ++index)
    // {
    //     cout << iArr[index] << '\t';
    // }
    // cout << endl;

    // plusTwo(iArr);

    // for(int index = 0; index < 10; ++index)
    // {
    //     cout << iArr[index] << '\t';
    // }
    // cout << endl;

    // pIArr= iArr;

    // cout << *pIArr++ << endl;
    // cout << *pIArr << endl;

    for(int index = 0; index < 10; ++index)
    {
        cout << count_calls() << '\t';
    }
    cout << endl;

    return 0;
}