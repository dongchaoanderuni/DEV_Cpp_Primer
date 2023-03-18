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
    VECTOR<INT>::size_type count(0);


    while(cin>>var)
    {
        varVec.push_back(var);
    }

    if(varVec.empty())
    {
        cout << "Vector is empty" << endl;
        goto FINISH;
    }

    count = varVec.size();
    cout << count << endl;

    for(decltype(varVec.size()) index = 0; index < count/2 + 1 ; index++)
    {
        cout << "index:" << index << " l:" << varVec[index] << "\t r: " << varVec[count-1-index];
        leftVar = varVec[index];
        rightVar = varVec[count-1-index];
        cout << "\t sum: "<<leftVar + rightVar << endl;
    }
    cout << endl;

FINISH:
    return 0;

}