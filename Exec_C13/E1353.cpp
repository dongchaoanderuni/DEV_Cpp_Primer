#include "Print.h"
#include <cstring>
#include "HasPtr.h"


using namespace std;

#define LegalInput (2)

int main()
{
	HasPtr hp("hi mom");
	HasPtr hp2(hp);
	
    hp.print();
	hp = hp2; // hp2 is an lvalue; copy constructor used to copy hp2 
    hp2.print();

    hp = std::move(hp2); // move constructor moves hp2
    hp2.print();

}
