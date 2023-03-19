
#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

class Y;

class X
{
    Y* py;
};

class Y
{
    X classX;
};


int main()
{

    return 0;
}
