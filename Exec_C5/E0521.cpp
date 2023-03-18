#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

#define targetCount (2)

int main()
{
    string  str{};
    string  target{};

    while(cin>>str)
    {
        if((target == str)
            &&(isupper(str[0])))
        {
            break;
        }
        else
        { 
            target = str;
        }
    }

    cout << "first target string:\t" << target << endl;

    return 0;
}