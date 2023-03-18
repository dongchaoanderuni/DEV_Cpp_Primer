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

void addPrefixAndSuffix(string &s, const string &prefix, const string &suffix)
{
    s.insert(0,prefix);
    s.insert(s.size()," " + suffix);
}

int main(int argc, char* argv[])
{
    string s = "Mike";
    vector<string> vecStr;

    addPrefixAndSuffix(s, "Mr.", "Jr.");


    cout << s << endl;

    return 0;
}
