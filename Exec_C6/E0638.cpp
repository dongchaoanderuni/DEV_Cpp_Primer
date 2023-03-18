#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

extern string (&func(int i))[10];

typedef string arrStr[10];

extern arrStr &func();

auto func()-> string(&)[10];

string strArr[10];

extern decltype(strArr) &funcDeclt(int i);

int odd[]     = {1,3,5,7,9};
int even[]   = {2,4,6,8,0};

int (&arrPtr(int i))[5]
{
    return ((i%2)?odd:even);
}

int main()
{
    int i{0};
    while(cin >> i)
    {
        for(auto ele:arrPtr(i))
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}