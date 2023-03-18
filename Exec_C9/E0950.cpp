#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
// #include "Sales_data.h"
#include "Variable.h"

using namespace std;

int sumofVecStr(vector<string> &vecStr)
{
    int sum = 0;
    for(auto ele:vecStr)
    {
        sum += stoi(ele);
    }
    return sum;
}



int main(int argc, char* argv[])
{
    vector<string> vecStr = {"1","+33.14", "-32767"};


    cout << sumofVecStr(vecStr) << endl;

    return 0;
}
