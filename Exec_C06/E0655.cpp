#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

int func(int, int);

int Algorithmplus(int inputEins, int inputZwei)
{
    cout  << "plus:\t";
    return inputEins + inputZwei;
}

int Algorithmminus(int inputEins, int inputZwei)
{
    cout  << "minus:\t";
    return inputEins - inputZwei;
}

int Algorithmproduct(int inputEins, int inputZwei)
{
    cout  << "product:\t";
    return inputEins * inputZwei;
}

int Algorithmdivide(int inputEins, int inputZwei)
{
    cout  << "divide:\t";
    return inputEins / inputZwei;
}

int main()
{
    vector<int(*)(int, int)> vec;
    int inputEins{0};
    int inputZwei{0};

    // int (*ele)(int, int);

    // ele = plus;

    vec.push_back(&Algorithmplus);
    vec.push_back(&Algorithmminus);
    vec.push_back(&Algorithmproduct);
    vec.push_back(&Algorithmdivide);

    while(cin >> inputEins >> inputZwei)
    {
        for(auto elem:vec)
        {
            cout << elem(inputEins, inputZwei) << endl;
        }

    }
    return 0;
}
