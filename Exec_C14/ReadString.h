#ifndef READSTRING_H
#define READSTRING_H

#include <iostream>

using namespace std;

class ReadString
{
public:
    ReadString(istream &is=cin):is(is) {}
    string operator()() const {string line; if(!getline(is, line)){line = "";} return line;}
private:
    istream &is;
};

#endif