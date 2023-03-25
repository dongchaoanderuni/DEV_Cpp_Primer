#ifndef __TEMPLATEVEC_H__
#define __TEMPLATEVEC_H__

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

template <typename T>
class Vec;

template <typename T>
bool operator==(const Vec<T>&, const Vec<T> &);

template <typename T>
bool operator!=(const Vec<T>&, const Vec<T> &);

template <typename T>
bool operator<(const Vec<T>&, const Vec<T> &);

template <typename T>
bool operator<=(const Vec<T>&, const Vec<T> &);

template <typename T>
bool operator>(const Vec<T>&, const Vec<T> &);

template <typename T>
bool operator>=(const Vec<T>&, const Vec<T> &);

template <typename T>
void print(Vec<T>&);

template <typename T>
void print(const Vec<T>&);

template <typename T>
class Vec
{
friend bool operator==  <T>(const Vec<T>&, const Vec<T> &);
friend bool operator!=  <T>(const Vec<T>&, const Vec<T> &);
friend bool operator<   <T>(const Vec<T>&, const Vec<T> &);
friend bool operator<=  <T>(const Vec<T>&, const Vec<T> &);
friend bool operator>   <T>(const Vec<T>&, const Vec<T> &);
friend bool operator>=  <T>(const Vec<T>&, const Vec<T> &);
friend void print<T>(Vec<T>&);
friend void print<T>(const Vec<T>&);
public:
    Vec():elements(nullptr),first_free(nullptr),cap(nullptr) {}
    Vec(Vec &&vec) noexcept;
    Vec(const Vec&);
    Vec(initializer_list<T>);
    Vec operator=(const Vec&);
    Vec operator=(Vec &&) noexcept;
    Vec operator=(initializer_list<T>);
    T& operator[](size_t n);
    ~Vec(); 

    void push_back(const T&);
    void push_back(T&&);
    void reserve(size_t);
    void reserve(size_t, T&);
    void resize(size_t);
    void resize(size_t, T &t);
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}

    T* begin() const {return elements;}
    T* end() const {return first_free;}

private:
    allocator<T> alloc;
    void chk_n_alloc() {if(size() == capacity()) reallocate();}
    pair<T*, T*> alloc_n_copy(const T*, const T*);
    void free();
    void reallocate();
    void reallocate(size_t n);
    T* elements;
    T* first_free;
    T* cap;
};

template <typename T>
Vec<T>::Vec(const Vec<T>&rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    elements =  data.first;
    first_free = cap = data.second;
}

template <typename T>
Vec<T>::Vec(Vec<T> &&vec) noexcept
{
    free();
    elements = std::move(vec.elements);
    first_free = std::move(vec.first_free);
    cap = std::move(vec.cap);   
    vec.elements = vec.first_free = vec.cap = nullptr;
}

template <typename T>
Vec<T>::Vec( initializer_list<T> rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    elements = data.first;
    first_free = cap = data.second; 
}

template <typename T>
Vec<T> Vec<T>::operator=(const Vec<T>& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template <typename T>
Vec<T> Vec<T>::operator=(Vec<T>&& rhs) noexcept
{
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;

        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

template <typename T>
Vec<T> Vec<T>::operator=(initializer_list<T> rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    elements = data.first;
    first_free = cap = data.second; 
    return *this;
}


template <typename T>
void Vec<T>::push_back(const T& str)
{
    chk_n_alloc();
    alloc.construct(first_free++, str);
}

template <typename T>
void Vec<T>::push_back(T&& str)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(str));
}

template <typename T>
pair<T*, T*> Vec<T>::alloc_n_copy(const T*begin, const T*end)
{
    /** 分配内存 */
    auto data = alloc.allocate(end - begin);
    /**  uninitialized_copy 初始化 */
    return {data, uninitialized_copy(begin, end, data)};
}

template <typename T>
void Vec<T>::reserve(size_t n)
{
    if(n > capacity())
    {
        reallocate(n);
    }
}

template <typename T>
void Vec<T>::free()
{
    if(elements)
    {
        for(auto p = first_free; p != elements; )
        {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap-elements);
    }
}

template <typename T>
Vec<T>::~Vec()
{
    free();
}

template <typename T>
void Vec<T>::reallocate()
{
    auto newcapacity = size()? 2 * size():1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;

    for(size_t i = 0; i != size(); i++)
    {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();

    elements = newdata;
    first_free = dest;
    cap= elements + newcapacity;
}
template <typename T>
void Vec<T>::reallocate(size_t newcapacity)
{
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;

    for(size_t i = 0; i != size(); i++)
    {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();

    elements = newdata;
    first_free = dest;
    cap= elements + newcapacity;
}

template <typename T>
void Vec<T>::resize(size_t n)
{
    if(n < size())
    {
        alloc.destroy(--first_free);
    }
    else if(size() < n)
    {
        while(size() < n )
        {
            push_back(' ');
        }
    }

}

template <typename T>
void Vec<T>::resize(size_t n, T& str)
{
    if(n < size())
    {
        alloc.destroy(--first_free);
    }
    else if(size() < n)
    {
        while(size() < n )
        {
            push_back(str);
        }
    }
}

template <typename T>
bool operator== (const Vec<T>& lhs, const Vec<T> &rhs)
{
    if(lhs.size() != rhs.size())
    {
        return false;
    }
    for(auto iterEins = lhs.begin(), iterZwei  = rhs.begin(); iterEins != lhs.end(); iterEins++, iterZwei++)
    {
        if(*iterEins != *iterZwei)
        {
            return false;
        }
    }
    return true;
}

template <typename T>
bool operator!= (const Vec<T>& lhs, const Vec<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool StringCmp(const T&lhs, const T&rhs)
{
    auto iterLhs = lhs.begin();
    auto iterRhs = rhs.begin();
    while((iterLhs != lhs.end())&&(*iterLhs == *iterRhs))
    {
        iterLhs++;
        iterRhs++;
    }

    return (*iterLhs - *iterRhs);
}

template <typename T>
bool operator<(const Vec<T>& lhs, const Vec<T>& rhs)
{
    auto iterEins = lhs.begin();
    auto iterZwei = lhs.begin();
        for(; iterEins != lhs.end()&&iterZwei != rhs.end();iterEins++,iterZwei++)
    {
        if(*iterEins < *iterZwei)
        {
            return true;
        }
        else if(*iterEins > *iterZwei)
        {
            return false;
        }
    }

    if((iterEins == lhs.end())
        &&(iterZwei != rhs.end()))
    {
        return true;
    }

    return true;
}

template <typename T>
bool operator<=(const Vec<T>& lhs, const Vec<T>& rhs)
{
    auto iterEins = lhs.begin();
    auto iterZwei = rhs.begin();

    for(; iterEins != lhs.end()&&iterZwei != rhs.end();iterEins++,iterZwei++)
    {
        if(*iterEins < *iterZwei)
        {
            return true;
        }
        else if(*iterEins > *iterZwei)
        {
            return false;
        }
    }

    if(iterEins == lhs.end())
    {
        return true;
    }

    return true;
}

template <typename T>
bool operator>=(const Vec<T>& lhs, const Vec<T>& rhs)
{
    auto iterEins = lhs.begin();
    auto iterZwei = rhs.begin();

    for(; iterEins != lhs.end()&&iterZwei != rhs.end();iterEins++,iterZwei++)
    {
        if(*iterEins < *iterZwei)
        {
            return false;
        }
        else if(*iterEins > *iterZwei)
        {
            return true;
        }
    }

    if(iterZwei == rhs.end())
    {
        return true;
    }

    return true;
}

template <typename T>
bool operator>(const Vec<T>& lhs, const Vec<T>& rhs)
{
    auto iterEins = lhs.begin();
    auto iterZwei = rhs.begin();

    for(; iterEins != lhs.end()&&iterZwei != rhs.end();iterEins++,iterZwei++)
    {
        if(*iterEins < *iterZwei)
        {
            return false;
        }
        else if(*iterEins > *iterZwei)
        {
            return true;
        }
    }

    if((iterZwei == rhs.end())
        &&(iterEins != lhs.end()))
    {
        return true;
    }

    return true;
}

template <typename T>
T& Vec<T>::operator[](size_t n)
{
    return (elements[n]);
}

template <typename T>
void print(Vec<T>&rhs)
{
    for(size_t i = 0; i != rhs.size(); i++)
    {
        cout << rhs[i] << " ";
    }
    cout << endl;
}

template <typename T>
void print(const Vec<T>&rhs)
{
    for(auto begin = rhs.begin(); begin != rhs.end(); begin++)
    {
        cout << *begin << " ";
    }
    cout << endl;
}


#endif