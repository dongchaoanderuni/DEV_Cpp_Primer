#include "Print.h"
#include <cstring>

using namespace std;

#define LegalInput (2)

class HasPtr
{
public:
    HasPtr(const string &s = string()):ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr & hasPtr):ps(hasPtr.ps), i(hasPtr.i), use(hasPtr.use) {++*use;}
    HasPtr &operator =(const HasPtr &hasPtr);
    HasPtr &operator =(const string &str);
    string &operator *() {return *ps;}
    
    ~HasPtr() {if(--*use==0){delete ps; delete use;}}
    


    void print() {cout << *this->ps << " i: " << this->i << endl; }

private:
    string *ps;
    int i;
    size_t *use;
};

HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use;
    if(--*use==0)
    {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    
    return *this;
}

HasPtr &HasPtr::operator=(const string &str)
{
    ps = new string(str);
    i = 0;
    use = new size_t(1);

    return *this;
}

int main(int argc, char* argv[])
{



    return 0;
}
