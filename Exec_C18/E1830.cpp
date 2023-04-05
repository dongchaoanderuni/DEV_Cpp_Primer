#include "Headfile.h"

using namespace std;

class Class
{
    //...
};

class Base: public Class
{
public:
    Base():ival(0) {}
    Base(int value):ival(value) {}
    Base(Base& b):ival(b.ival) {}
private:
    int ival;
};

class D1: virtual public Base
{
public:
    D1():Base() {}
    D1(int value):Base(value) {}
    D1(D1& dEins):Base(dEins) {}
};

class D2: virtual public Base
{
public:
    D2():Base() {}
    D2(int value):Base(value) {}
    D2(D2& dEins):Base(dEins) {}
};

class MI: public D1, public D2
{
public:
    MI():D1(), D2() {}
    MI(int value):D1(value), D2(value) {}
    MI(MI& miEins):D1(miEins), D2(miEins) {}
};

class Final: public MI, public Class
{
public:
    Final():Base(), MI() {}
    Final(int value): Base(value), MI(value) {}
    Final(Final& fEins): Base(fEins), MI(fEins) {}
};



int main() 
{
    cout << "Hello World! " << endl;
    
    return 0;
}
