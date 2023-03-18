#include "Print.h"
#include <cstring>

using namespace std;

#define LegalInput (2)

class HasPtr
{
friend void swap(HasPtr&, HasPtr&);

public:
    HasPtr(const string &s = string()):ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr & hasPtr):ps(hasPtr.ps), i(hasPtr.i), use(hasPtr.use) {++*use;}
    HasPtr &operator =(const HasPtr &hasPtr);
    HasPtr &operator =(const string &str);
    bool operator <(const HasPtr &hasPtr) const {cout <<"*ps:" <<*ps << " hasPtr:"<<*hasPtr.ps<<endl; return *ps < *hasPtr.ps;}
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

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    cout << "swap:" << *lhs.ps << " " << *rhs.ps << endl; 
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main(int argc, char* argv[])
{
    if(LegalInput != argc)
    {
        cout << __LINE__ << " input params not legal " << argc << endl;
        return -1;
    }

    ifstream inFile(argv[1]);
    if(!inFile)
    {
        cerr << "Input File parse failed." << endl;
    }

    istream_iterator<string> in(inFile), eof;
    vector<HasPtr> vecHasPtr(in, eof);

    for(auto ele:vecHasPtr)
    {
        ele.print();
    }
    sort(vecHasPtr.begin(), vecHasPtr.end());

    cout << "sorted" << endl;

    for(auto ele:vecHasPtr)
    {
        ele.print();
    }

    return 0;
}
