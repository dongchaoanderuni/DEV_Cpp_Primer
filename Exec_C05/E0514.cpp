#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

int main()
{
    string  str{};
    string  target{};
    int     count{0};
    int     maxcount{0};
    string  maxtarget{};
    while(cin>>str)
    {
        if(target.empty())
        {
            target = str;
        }

        if(target == str)
        {
            ++count;
        }
        else
        {
            if(maxcount<count)
            {
                maxcount    =   count;
                maxtarget   =   target;
            }
            target = str; 
            count = 1;
        }
    }

    if(maxcount > 1)
    {
        cout << "total number of " << maxtarget << " :\t" << maxcount << endl;
    }
    else
    {
        cout << "All of the word just once." << endl;
    }

    return 0;
}