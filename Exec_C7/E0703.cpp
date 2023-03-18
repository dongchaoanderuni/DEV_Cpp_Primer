#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

struct Person
{
    string firstName;
    string lastName;
    string address;

    string getFirstName() const {return firstName;}
    string getLastName() const  {return lastName;}
    string getAddress() const   {return address;}
};

int main()
{



    return 0;
}
