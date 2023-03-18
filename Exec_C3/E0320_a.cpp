#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
#include "Variable.h"

using namespace std;

int main()
{
    
    VECTOR<INT> varVec;
    INT leftVar(0);
    INT rightVar(0);
    INT var(0);
    BOOLEAN FirstFlag = TRUE;


    while(cin>>var)
    {
        if(FirstFlag)
        {
            leftVar = var;
            FirstFlag = FALSE;
        }
        rightVar = var;
        cout << leftVar + rightVar << ' ';

        leftVar = rightVar;
        varVec.push_back(var);

    }

    return 0;

}