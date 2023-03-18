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
    
    //构造
    StrBlob();
    typedef vector<string>::size_type size_type;
    StrBlob(initializer_list<string> il);
    StrBlob(StrBlob &s);
    StrBlob &operator=(StrBlob &rhs);

    //属性访问
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}
    
    // 提供给StrBlobStr和ConstStrBlobStr的接口
    StrBlobPtr begin();
    StrBlobPtr end();
    ConstStrBlobPtr cbegin() const;
    ConstStrBlobPtr cend() const;

    // 添加和删除元素
    void push_back(const string &t) {data->push_back(t);}
    void push_back(string &&t) noexcept {data->push_back(std::move(t));}
    void pop_back();
    
    // 元素访问
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

inline StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}
inline StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {}
inline StrBlob::StrBlob(StrBlob &s): data(make_shared<vector<string>>(*s.data)) {}
inline StrBlob &StrBlob::operator=(StrBlob &rhs) {data = make_shared<vector<string>>(*rhs.data); return *this;}

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

#endif

