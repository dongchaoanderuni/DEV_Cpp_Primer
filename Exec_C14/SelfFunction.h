#ifndef SELFFUNCTION_H
#define SELFFUNCTION_H

using namespace std;

class SELFFUNCTION
{
public:
    int operator()(bool flag,int zwei, int drei) const {return flag?zwei:drei;}
private:
};

#endif