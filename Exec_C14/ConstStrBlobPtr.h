#ifndef __CONSTSTRBLOBPTR_H__
#define __CONSTSTRBLOBPTR_H__

#include "StrBlob.h"

using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;

class ConstStrBlobPtr
{
friend bool eq(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

public:
    ConstStrBlobPtr(): curr(0) {};
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    string &deref() const;
    ConstStrBlobPtr& incr(); 
    
    const string& operator*() const {auto p = check(curr, "dereference past end."); return (*p)[curr];}
    const string* operator->() const {return &(*this->operator*());}

private:
    shared_ptr<vector<string>> check(size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};


inline ConstStrBlobPtr StrBlob::cbegin() const
{   
    return ConstStrBlobPtr(*this);
}

inline ConstStrBlobPtr StrBlob::cend() const
{
    auto ret = ConstStrBlobPtr(*this, data->size()); 
    return ret;
}

string &ConstStrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end.");
    return (*p)[curr];
}

inline ConstStrBlobPtr &ConstStrBlobPtr::incr()
{
    check(curr, "increment past end of ConstStrBlobPtr.");
    ++curr;
    return *this;
}

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t sz, const string& msg) const
{
    auto ret = wptr.lock();
    if(!ret)
    {
        throw runtime_error("unbound ConstStrBlobPtr");
    }
    if(sz >= ret->size())
    {
        throw out_of_range(msg);
    }

    return ret;
}


inline bool eq(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    auto left = lhs.wptr.lock();
    auto right = rhs.wptr.lock();
    if(left == right)
    {
        return(!right || lhs.curr == rhs.curr);
    }
    return false;
    
}

inline bool neq(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return !eq(lhs,rhs);
}



#endif