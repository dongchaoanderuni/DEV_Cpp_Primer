#ifndef __STRVEC_H__
#define __STRVEC_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <map>
#include <unordered_map>          
#include <set>         
#include <unordered_set>
#include <new>
#include <memory>
#include <initializer_list>
#include <string>
#include <stdexcept>
#include <utility>


using namespace std;

class StrVec
{
public:
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){};
    typedef size_t size_type;
    
    StrVec(StrVec &&strVec) noexcept;
    StrVec(const StrVec&);
    StrVec(initializer_list<string>&);
    StrVec &operator=(const StrVec&);
    StrVec &operator=(StrVec &&) noexcept;
    ~StrVec();

    void push_back(const string&);
    void push_back(string&& str);
    void reserve(size_t n);
    void resize(size_t n);
    void resize(size_t n, string &t);
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}

    string *begin() const {return elements;}
    string *end() const {return first_free;}

private:
    /* data */
    allocator<string> alloc;
    void chk_n_alloc() {if(size()==capacity()) reallocate();}
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
    void reallocate(size_t n);
    string *elements;
    string *first_free;
    string *cap;
};

inline StrVec::StrVec(const StrVec& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
}

inline StrVec::StrVec(StrVec &&strVec) noexcept:elements(strVec.elements), first_free(strVec.first_free), cap(strVec.cap)
{
    strVec.elements = strVec.first_free=strVec.cap = nullptr;
}

inline StrVec::StrVec(initializer_list<string> &rhs)
{
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

void StrVec::push_back(const string& str)
{
    chk_n_alloc();

    alloc.construct(first_free++, str);
}

void StrVec::push_back(string&& str)
{
    chk_n_alloc();

    alloc.construct(first_free++, std::move(str));
}


pair<string*, string*> StrVec::alloc_n_copy(const string *begin, const string *end)
{
    auto data = alloc.allocate(end-begin);
    return {data, uninitialized_copy(begin, end, data)};
}

void StrVec::reserve(size_t n)
{
    if(n > capacity())
    {
        reallocate(n);
    }
}

// void StrVec::free()
// {
//     if(elements)
//     {
//         for(auto p = first_free; p != elements; )
//         {
//             alloc.destroy(--p);
//         }
//         alloc.deallocate(elements, cap-elements);
//     }
// }

void StrVec::free()
{
    if(elements)
    {
        for_each(elements,first_free, [](string &s){alloc.destroy(&s)})
        alloc.deallocate(elements, cap-elements);
    }
}

StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    if(this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}


// void StrVec::reallocate()
// {
//     auto newcapacity = size() ? 2 * size() : 1;
//     auto newdata = alloc.allocate(newcapacity);
//     auto dest = newdata;
//     auto elem = elements;
//     for(size_t i = 0; i != size(); ++i)
//     {
//         alloc.construct(dest++, std::move(*elem++));
//     }
//     free();

//     elements = newdata;
//     first_free = dest;
//     cap = elements + newcapacity;
// }

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);
    auto last  = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);

    free();
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}

void StrVec::reallocate(size_t newcapacity)
{
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();

    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::resize(size_t n)
{
    if(n < size())
    {
        alloc.destroy(--first_free);
    }
    else if(size() < n)
    {
        while(size() < n)
        {
            push_back("");
        }
    }
}

void StrVec::resize(size_t n, string &t)
{
    if(n < size())
    {
        alloc.destroy(--first_free);
    }
    else if(size() < n)
    {
        while(size() < n)
        {
            push_back(t);
        }
    }
}

#endif