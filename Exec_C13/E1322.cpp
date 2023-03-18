#include "Print.h"
#include "StrBlob.h"
#include <cstring>


using namespace std;

#define LegalInput (2)

class HasPtr
{
public:
    HasPtr(const string &s = string(), int input = 0): ps(new string(s)), i(input) {cout << "HasPtr(const string &s = string(), int input = 0)" << endl;}
    HasPtr(const HasPtr & hasPtr) {ps = new string(*hasPtr.ps); i = hasPtr.i; cout << "HasPtr(const HasPtr & hasPtr) " << endl; }
    HasPtr &operator =(const HasPtr &hasPtr) {auto newps = new string(*hasPtr.ps); delete ps;ps = newps; i = hasPtr.i;  cout << "&operator =(const HasPtr &hasPtr) " << endl; return *this;}
    HasPtr &operator =(const string &str) {auto newps= new string(str); delete ps; ps = newps; cout << "HasPtr &operator =(const string &str) " << endl; return *this;}
    ~HasPtr() {delete ps;}
    
    void print() {cout << *this->ps << " i: " << this->i << endl; }


private:
    string *ps;
    int i;
};

int main(int argc, char* argv[])
{
    HasPtr hasPtr;
    HasPtr hasPtrZwei("abc");
    HasPtr hasPtrDrei(hasPtrZwei);

    hasPtr = "efg";
    hasPtrDrei = hasPtr;


    return 0;
}
