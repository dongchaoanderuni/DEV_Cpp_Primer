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


void plusTwoWithArr(int iArr[])
{
    for(int index = 0; index < 10; ++index)
    {
        iArr[index] *= 2; 
    }
}


void plusTwoWithRefArr(int (&iArr)[10])
{
    for(int index = 0; index < 10; ++index)
    {
        iArr[index] *= 2; 
    }
}

void plusTwoWithArrPtr(int *iArr)
{
    for(int index = 0; index < 10; ++index)
    {
        iArr[index] *= 2; 
    }
}


void swapValue(int &a, int &b)
{
    int c{0};
    c = a;
    a = b;
    b = a;

    return;
}

void swapValueWithPtr(int *a, int *b)
{
    int c{0};
    c = *a;
    *a = *b;
    *b = c;

    return;
}

void reset(int &input)
{
    input = 0;

    return;
}

int getBigValueBack(int a, int *b)
{
    if(a > *b)
    {
        return a;
    }
    return *b;
}


int main()
{
    // int iArr[10] = {0,1,2,3,4,5,6,7,8,9};
    
    // for(int index = 0; index < 10; ++index)
    // {
    //     cout << iArr[index] << '\t';
    // }
    // cout << endl;

    // plusTwoWithArr(iArr);
    // for(int index = 0; index < 10; ++index)
    // {
    //     cout << iArr[index] << '\t';
    // }
    // cout << endl;

    // plusTwoWithRefArr(iArr);

    // for(int index = 0; index < 10; ++index)
    // {
    //     cout << iArr[index] << '\t';
    // }
    // cout << endl;

    // plusTwoWithArrPtr(iArr);
    // for(int index = 0; index < 10; ++index)
    // {
    //     cout << iArr[index] << '\t';
    // }
    // cout << endl;

    int a{3};
    int b{4};

    cout << "a: " << a << "\tb: " << b << endl;
    swap(a,b);
    cout << "a: " << a << "\tb: " << b << endl;
    swapValueWithPtr(&a,&b);
    cout << "a: " << a << "\tb: " << b << endl;
    cout << "Big Value between a: " << a 
            << " and " << b  << " is " << getBigValueBack(a,&b) << endl;


    reset(a);
    reset(b);
    cout << "a: " << a << "\tb: " << b << endl;

    return 0;
}