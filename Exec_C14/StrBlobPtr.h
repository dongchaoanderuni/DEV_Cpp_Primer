#ifndef __STRBLOBPTR_H__
// we're here only if SALESITEM_H has not yet been defined 
#define __STRBLOBPTR_H__

#include "StrBlob.h"

using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob;

class  StrBlobPtr
{
friend bool eq(const StrBlobPtr &, const StrBlobPtr &);
inline bool neq(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
friend StrBlobPtr operator+(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr(): curr(0) {};
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    string &deref() const;
    StrBlobPtr& incr(); 

    string& operator*() const {auto p = check(curr, "dereference past end."); return (*p)[curr];}
    string* operator->() const {return &(this->operator*());}
    string& operator[](size_t n);
    const string& operator[](size_t n) const;
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    StrBlobPtr operator+(int);
    StrBlobPtr operator-(int);

private:
    shared_ptr<vector<string>> check(size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end.");
    return (*p)[curr];
}

inline StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr.");
    ++curr;
    return *this;
}

inline StrBlobPtr StrBlob::begin()
{   
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size()); 
    return ret;
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t sz, const string& msg) const
{
    auto ret = wptr.lock();
    if(!ret)
    {
        throw runtime_error("unbound StrBlobPtr");
    }
    if(sz >= ret->size())
    {
        throw out_of_range(msg);
    }

    return ret;
}

inline bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto left = lhs.wptr.lock();
    auto right = rhs.wptr.lock();
    if(left == right)
    {
        return(!right || lhs.curr == rhs.curr);
    }
    return false;
}

inline bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !eq(lhs,rhs);
}


inline bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto left = lhs.wptr.lock();
    auto right = rhs.wptr.lock();
    if(left < right)
    {
        if(!right)
        {
            return false;
        }
        return (lhs.curr < rhs.curr);
    }
    return false;
}

inline bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto left = lhs.wptr.lock();
    auto right = rhs.wptr.lock();
    if(left == right)
    {
        return(!right || lhs.curr == rhs.curr);
    }
    return false;
}

inline bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto left = lhs.wptr.lock();
    auto right = rhs.wptr.lock();
    if(left > right)
    {
        if(!right)
        {
            return false;
        }
        return (lhs.curr > rhs.curr);
    }
    return false;
}

inline bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto left = lhs.wptr.lock();
    auto right = rhs.wptr.lock();
    if(left == right)
    {
        return(!right || lhs.curr > rhs.curr);
    }
    return false;
}

inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto left = lhs.wptr.lock();
    auto right = rhs.wptr.lock();
    if(left == right)
    {
        return(!right || lhs.curr == rhs.curr);
    }
    return false;
    
}

inline bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !eq(lhs,rhs);
}

string& StrBlobPtr::operator[](size_t n)
{
    auto p = check(n, "index out of range");
    return (*p)[n];
}

const string& StrBlobPtr::operator[](size_t n) const
{
    auto p = check(n, "index out of range");
    return (*p)[n];
}

StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlobPtr::operator+(int n)
{
    auto ret = *this;
    ret.curr += n;
    check(ret.curr, "increment past end of StrBlobPtr");
    return ret;
}

StrBlobPtr StrBlobPtr::operator-(int n)
{
    auto ret = *this;
    ret.curr -= n;
    check(ret.curr, "decrease past end of StrBlobPtr");
    return ret;
}


StrBlobPtr& StrBlobPtr::operator--()
{
    --curr;
    check(curr, "decrease past end of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

#endif

