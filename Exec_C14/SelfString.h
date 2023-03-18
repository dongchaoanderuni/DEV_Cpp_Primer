#ifndef __SELFSTRING_H__
#define __SELFSTRING_H__

#include <cstring>
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <initializer_list>
#include <iostream>
#include <memory>

using namespace std;

class String
{
friend ostream& operator<<(ostream& os, const String &lhs);
friend bool operator==(const String&lhs, const String& rhs);
friend bool operator!=(const String&lhs, const String& rhs);
friend bool operator<(const String&lhs, const String&rhs);
friend bool operator<=(const String&lhs, const String&rhs);
friend bool operator>=(const String&lhs, const String&rhs);
friend bool operator>(const String&lhs, const String&rhs);

public:
    String():pChar(nullptr), sz(0) {}
    String(const char*);
    String(const String&);
    String(String &&) noexcept;


    char& operator[](size_t n);
    String &operator=(String &);
    String &operator=(const String &);
    String &operator=(std::initializer_list<char>);
    String &operator=(String &&) noexcept;
    ~String()  { if (!pChar) alloc.deallocate(begin(), size()); }

    size_t size() const {return sz;}
    char* begin()  {return pChar;}
    const char* begin() const {return pChar;}
    char* end()  {return pChar+sz;}
    const char* end() const {return pChar+sz;}

private:
    static allocator<char> alloc;
    size_t sz = 0;
    char *pChar =nullptr;

    void free();
    
};

void String::free()
{    
    if(!pChar)
    {
        alloc.deallocate(begin(), size());
    }
}

String::String(const char* pC):sz(strlen(pC)),pChar(alloc.allocate(sz))
{
    // cout << "String(const char* pC)" << endl;
    uninitialized_copy(pC, pC+sz, pChar);
}

String::String(const String & str)
{
    // cout << "String(const String & str) " << str.begin() << endl;

    free();
    sz = str.size();
    pChar = alloc.allocate(sz);
    uninitialized_copy(str.pChar,str.pChar+str.size(),pChar);
}

String::String(String &&str) noexcept
{
    if(this != &str)
    {
        free();
        pChar = str.pChar;
        sz = str.sz;
        str.pChar = nullptr;
        str.sz = 0;
    }
}

String &String::operator=(String && str) noexcept
{
    if(this != &str)
    {
        free();
        pChar = str.pChar;
        sz = str.sz;
        str.pChar = nullptr;
        str.sz = 0;
    }

    return *this;
}

String &String::operator=(const String & str)
{
    // cout << "operator=(const String & str)" << endl;
    free();
    sz = str.size();
    pChar = alloc.allocate(sz);
    uninitialized_copy(str.pChar,str.pChar+str.size(),pChar);

    return *this;
}

String& String::operator=(initializer_list<char> il)
{
	// no need to check for self-assignment
    free();
    sz = il.size();
           // do the work of the destructor
	pChar = alloc.allocate(sz); // do the work of the copy constructor
	uninitialized_copy(il.begin(), il.end(), pChar);
	return *this;
}

ostream& operator<<(ostream& os, const String &lhs)
{
    for(auto ele:lhs)
    {
        os << ele;
    }
    return os;
}

bool operator==(const String& lhs, const String& rhs)
{
    if(lhs.size() != rhs.size())
    {
        return false;
    }
    for(auto iterLhs = lhs.begin(), iterRhs = rhs.begin(); iterLhs != lhs.end(); iterLhs++,iterRhs++)
    {
        if(*iterLhs != *iterRhs)
        {
            return false;
        }
    }
    return true;
}

bool operator!=(const String& lhs, const String& rhs)
{
    return !(lhs == rhs);
}


int StringCmp(const String&lhs, const String&rhs)
{
    auto iterLhs = lhs.begin();
    auto iterRhs = rhs.begin();
    while((iterLhs != lhs.end())&&(*iterLhs == *iterRhs))
    {
        iterLhs++;
        iterRhs++;
    }

    if (iterLhs == lhs.end() && iterRhs == rhs.end()) // both strings are equal
        return 0;
    else if (iterLhs == lhs.end()) // lhs string is a prefix of rhs string
        return -1;
    else if (iterRhs == rhs.end()) // rhs string is a prefix of lhs string
        return 1;
    else // compare the first differing characters
        return (*iterLhs < *iterRhs) ? -1 : 1;
}

bool operator<(const String&lhs, const String&rhs)
{
    return (StringCmp(lhs,rhs) < 0);
}

bool operator<=(const String&lhs, const String&rhs)
{
    return (StringCmp(lhs,rhs) <= 0);
}

bool operator>(const String&lhs, const String&rhs)
{
    return (StringCmp(lhs,rhs) > 0);
}

bool operator>=(const String&lhs, const String&rhs)
{
    return (StringCmp(lhs,rhs) >= 0);
}

char& String::operator[](size_t n)
{

    return (pChar[n]);
}

#endif