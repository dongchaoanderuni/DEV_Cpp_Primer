#include "Print.h"
#include "StrBlob.h"
#include <cstring>
#include "HasPtr.h"


using namespace std;

#define LegalInput (2)

class Employee
{
friend void f(const Employee &s);

public:
    Employee():fullName(string()) {seqNo++;}
    Employee(const Employee &rhs) {fullName = rhs.fullName; seqNo++;}
    Employee(const string &str):fullName(str) {seqNo++;}
    Employee &operator =(const Employee &rhs) {fullName = rhs.fullName; seqNo++; return *this;} 

private:
    static int seqNo;
    string fullName;
};

int Employee::seqNo = 0;

// void f(numbered s) {cout << s.seqNo << endl;}
void f(const Employee &s) {cout << s.seqNo << endl;}


int main(int argc, char* argv[])
{
    Employee a("Chandler"), b = a, c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}
