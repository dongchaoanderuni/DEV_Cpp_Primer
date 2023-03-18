#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

void swapPtr(int *&a, int *&b)
{
    int *c{0};

    // cout <<"a:\t" << a << endl; 
    // cout <<"b:\t" << b << endl; 

    // cout <<"*a:\t" << *a << endl; 
    // cout <<"*b:\t" << *b << endl; 


    // cout <<"**a:\t" << **a << endl; 
    // cout <<"**b:\t" << **b << endl; 
    c = a;
    a = b;
    b = c;

    // cout <<"*a:\t" << *a << endl; 
    // cout <<"*b:\t" << *b << endl; 


    // cout <<"a:\t" << a << endl; 
    // cout <<"b:\t" << b << endl; 

    // cout <<"*a:\t" << *a << endl; 
    // cout <<"*b:\t" << *b << endl; 


    // cout <<"**a:\t" << **a << endl; 
    // cout <<"**b:\t" << **b << endl; 
}

int main()
{

    int a{3};
    int b{4};

    int* ipEins;
    int* ipZwei; 

    ipEins = &a;
    ipZwei = &b;

    cout << "a: " << a << "\tb: " << b << endl;
    cout << "ipEins: " << ipEins << "\tipZwei: " << ipZwei << endl;
    cout << "ipEins: " << *ipEins << "\tipZwei: " << *ipZwei << endl;
    swapPtr(ipEins,ipZwei);
    cout << "a: " << a << "\tb: " << b << endl;
    cout << "ipEins: " << ipEins << "\tipZwei: " << ipZwei << endl;
    cout << "ipEins: " << *ipEins << "\tipZwei: " << *ipZwei << endl;

    return 0;

}