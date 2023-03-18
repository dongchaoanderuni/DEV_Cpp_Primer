#ifndef __HASPTR_H__
// we're here only if SALESITEM_H has not yet been defined 
#define __HASPTR_H__

#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
friend void swap(HasPtr &lhs, HasPtr &rhs);

public:
    HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
    HasPtr(const HasPtr & hasPtr):ps(new string(*hasPtr.ps)), i(hasPtr.i) {}
    HasPtr(HasPtr &&hasPtr) noexcept:ps(hasPtr.ps), i(hasPtr.i) {hasPtr.ps = nullptr;}
    HasPtr &operator=(const HasPtr &hasPtr) {cout << "Copy" << endl; auto newps = new string(*hasPtr.ps); delete ps;ps = newps; i = hasPtr.i; return *this;}
    HasPtr &operator=(HasPtr &&hasPtr);
    // HasPtr &operator=(HasPtr hasPtr) {swap(*this, hasPtr); return *this;}
    ~HasPtr() {delete ps;}
    
    void print() {cout << *this->ps << " i: " << this->i << endl; }


private:
    string *ps;
    int i;
};

HasPtr& HasPtr::operator=(HasPtr &&hasPtr) 
{
    cout << "Construct" << endl; 
    if(this != &hasPtr)
    {
        delete ps;
        ps = hasPtr.ps;
        i = hasPtr.i;
        hasPtr.ps = nullptr;
        i = 0;
    }
    return *this;
}

void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

#endif