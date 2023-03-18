#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

struct Person
{
    Person() = default;
    Person(string &s): firstName(s) {}
    Person(string &s1, string &s2): firstName(s1), lastName(s2) {}
    Person(string &s1, string &s2, string &s3): firstName(s1), lastName(s2), address(s3) {}
    Person(istream &s);

    string firstName;
    string lastName;
    string address;

    string getFirstName() const {return firstName;}
    string getLastName() const  {return lastName;}
    string getAddress() const   {return address;}
};

Person add(const Person&, const Person&);
ostream &print(ostream&, const Person&);
istream &read(istream&, Person&);

Person::Person(istream &s)
{
    read(s, *this);
}

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
