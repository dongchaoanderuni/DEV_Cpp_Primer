#ifndef STATICLENGTHINARTICLE_H
#define STATICLENGTHINARTICLE_H

#include <iostream>

using namespace std;

class StaticLength
{
public:
    StaticLength(size_t size):sz(size) {}
    // bool operator()(string str) {return (str.length()==sz);}
    bool operator()(string str) {return (str.length()<=sz);}
    size_t size() const {return sz;}
private:
    size_t    sz;
};



#endif