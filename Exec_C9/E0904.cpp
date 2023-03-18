#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <vector>
#include <string>
// #include "Sales_data.h"
#include "Variable.h"

using namespace std;

#define LegalInput (2)

bool isTargetValueFindInVector(vector<int>::iterator &begin, vector<int>::iterator &end, int targetValue)
{
    for(auto index = begin; index != end; ++index)
    {
        if(*index == targetValue)
        {
            return TRUE;
        }
    }

    return FALSE;
}

int main(int argc, char* argv[])
{
    vector<int> vectInt;
    int input;
    int targetValue;

    if(2 != argc)
    {
        cout << __LINE__ << " input params not legal " << argc << endl;
        return -1;
    }

    ifstream in(argv[1]);

    while(in>>input)
    {
        vectInt.push_back(input);
    }

    cout << "Enter the target value" << endl;

    cin >> targetValue;

    vector<int>::iterator begin = vectInt.begin();
    vector<int>::iterator end = vectInt.end();

    cout <<targetValue << " in vector is : " <<  (isTargetValueFindInVector(begin, end, targetValue)?"True":"False") << endl;


    return 0;
}
