#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

string makePlural(size_t ctr, const string& s1, 
                    const string &s2 = "s")
{
    return ((ctr > 1)?s1+s2:s1);
}

int main()
{
    cout << makePlural(1,"success") << endl;
    cout << makePlural(2,"success", "es") << endl;
    cout << makePlural(1,"failure") << endl;
    cout << makePlural(2,"failure") << endl;

    return 0;
}