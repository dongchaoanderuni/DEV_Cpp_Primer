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

    if(v2.empty())
    {
        cout << "v2 is empty." << endl;
    }
        
    if(v3.empty())
    {
        cout << "v3 is empty." << endl;
    }

    if(v4.empty())
    {
        cout << "v4 is empty." << endl;
    }

    if(v5.empty())
    {
        cout << "v5 is empty." << endl;
    }

    if(v6.empty())
    {
        cout << "v6 is empty." << endl;
    }

    if(v7.empty())
    {
        cout << "v7 is empty." << endl;
    }


    cout << "v2:  ";
    
    for(auto it = v2.cbegin(); it != v2.cend(); ++it)
    {
        cout << i << ":" << *it  << "\t";
        i++;
    }
    cout << endl;

    i = init;

    cout << "v3:  ";
    for(auto it = v3.cbegin(); it != v3.cend(); ++it)
    {
        cout << i << ":" << *it  << "\t";
        i++;
    }
    cout << endl;

    i = init;
    cout << "v4:  ";
    for(auto it = v4.cbegin(); it != v4.cend(); ++it)
    {
        cout << i << ":" << *it  << "\t";
        i++;
    }
    cout << endl;

    i = init;

    cout << "v5:  ";
    for(auto it = v5.cbegin(); it != v5.cend(); ++it)
    {
        cout << i << ":" << *it  << "\t";
        i++;
    }
    cout << endl;

    i = init;
    cout << "v6:  ";
    for(auto it = v6.cbegin(); it != v6.cend(); ++it)
    {
        cout << i << ":" << *it  << "\t";
        i++;
    }
    cout << endl;

    i = init;
    cout << "v7:  ";
    for(auto it = v7.cbegin(); it != v7.cend(); ++it)
    {
        cout << i << ":" << *it  << "\t";
        i++;
    }
    cout << endl;

    return 0;

}