#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"

using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10,42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    int i = 0;
    const int init = 0;

    if(v1.empty())
    {
        cout << "v1 is empty." << endl;
    }


    cout << "v2:  ";
    
    for(auto &r:v2)
    {
        cout << i << ":" <<  r  << "\t";
        i++;
    }
    cout << endl;

    i = init;

    cout << "v3:  ";
    for(auto &r:v3)
    {
        cout << i << ":" <<  r  << "\t";
        i++;
    }
    cout << endl;

    i = init;

    cout << "v4:  ";
    for(auto &r:v4)
    {
        cout << i << ":" <<  r  << "\t";
        i++;
    }
    cout << endl;

    i = init;

    cout << "v5:  ";
    for(auto &r:v5)
    {
        cout << i << ":" <<  r  << "\t";
        i++;
    }
    cout << endl;

    i = init;
    cout << "v6:  ";
    for(auto &r:v6)
    {
        cout << i << ":" <<  r  << "\t";
        i++;
    }
    cout << endl;

    i = init;
    cout << "v7:  ";
    for(auto &r:v7)
    {
        cout << i << ":" <<  r  << "\t";
        i++;
    }
    cout << endl;

    return 0;

}