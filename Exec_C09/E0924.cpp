#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <vector>
#include <string>
#include <list>
#include <deque>
// #include "Sales_data.h"
#include "Variable.h"

using namespace std;

int main(int argc, char* argv[])
{
    vector<int> vecInt;

    cout << vecInt.front() << endl;
    cout << *vecInt.begin() << endl;
    cout << vecInt.at(0) << endl;

    return 0;
}
