#ifndef __STRBLOB_H__
// we're here only if SALESITEM_H has not yet been defined 
#define __STRBLOB_H__

#include <memory>
#include <initializer_list>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
friend class StrBlobPtr;
friend class ConstStrBlobPtr;
public:
    StrBlob();
    typedef vector<string>::size_type size_type;
    StrBlob(initializer_list<string> il);
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}
    StrBlobPtr begin();
    StrBlobPtr end();
    ConstStrBlobPtr cbegin() const;
    ConstStrBlobPtr cend() const;

    void push_back(const string &t) {data->push_back(t);}
    void pop_back();
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const
{
    if(i >= data->size())
    {
        throw out_of_range(msg);
    }
}

string& StrBlob::front()
{
    check(0, "front on empty StrBlob.");
    return data->front();
}

const string& StrBlob::front() const
{
    check(0, "front on empty StrBlob.");
    return data->front();
}

string& StrBlob::back()
{
    check(0,"back on empty StrBlob.");
    return data->back();
}

const string& StrBlob::back() const
{
    check(0,"back on empty StrBlob.");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0,"pop back on empty StrBlob.");
    return data->pop_back();
}

class  StrBlobPtr
{
friend bool eq(const StrBlobPtr &, const StrBlobPtr &);

public:
    StrBlobPtr(): curr(0) {};
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    string &deref() const;
    StrBlobPtr& incr(); 

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

class ConstStrBlobPtr
{
friend bool eq(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

public:
    ConstStrBlobPtr(): curr(0) {};
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    string &deref() const;
    ConstStrBlobPtr& incr(); 

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
    check(curr, "increment past end of StrBlobPtr.");
    ++curr;
    return *this;
}

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t sz, const string& msg) const
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

