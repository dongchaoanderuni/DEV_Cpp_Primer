#include "Headfile.h"
#include <cstdlib>
#include <typeinfo>

using namespace std;

class A 
{
public:
    virtual ~A() {};
};
class B: public A 
{
public:
    virtual ~B() {};
};
class C: public B {};
// class D: public A, public B {};

int main() 
{
    A *pa = new A;
    try
    {
        C &c = dynamic_cast<C&> (*pa);
    }
    catch(std::bad_cast &bc)
    {
        cout << "dynamic_cast failed.\n" << endl;
    }


    return 0;
}
