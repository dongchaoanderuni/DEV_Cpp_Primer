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

istream &read(istream &is, Person &item)
{
    is >> item.firstName >> item.lastName >> item.address;
    return is;
}

ostream &print(ostream &os, const Person &item)
{
    os << item.getFirstName() << "  " << item.getLastName() << " livs in "
        << item.getAddress() ;
    
    return os;
}



int main()
{



    return 0;
}
