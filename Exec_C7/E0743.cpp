#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>
// #include "Sales_data.h"


using namespace std;

class NoDefault
{
public:
    NoDefault(int i) {member = i;}
    int member;
};

class C
{
public:
    C(int i = 0):no(i) {}

    NoDefault no;
};

int main()
{
    // vector<NoDefault> vec(10);
    vector<C> vec(10);
    for(auto ele:vec)
    {
        cout << ele.no.member << endl;
    }

    return 0;
}
