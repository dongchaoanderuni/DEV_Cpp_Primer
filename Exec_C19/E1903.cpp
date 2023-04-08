#include "Headfile.h"
#include <cstdlib>

using namespace std;

class A {};
class B: public A 
{
public:
    virtual ~B() {};
};
class C: public B {};
// class D: public A, public B {};

int main() 
{
    cout << "Hello World! " << endl;

    B* pb = new B;
    C* pc = dynamic_cast<C*> (pb);


    return 0;
}
