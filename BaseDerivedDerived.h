#ifndef __BASEDERIVEDDEREIVD_H__
#define __BASEDERIVEDDEREIVD_H__

using namespace std;

class Base
{
public:
    void pub_mem();
protected:
    int protectedMem;
private:
    int privateMem;
};

class PubDerv:public Base
{
public:
    int f() {return protectedMem;}
    void memfcn(Base &b) {b = *this;}
};

class ProtectDerv:protected Base
{
public:
    int f() {return protectedMem;}
    void memfcn(Base &b) {b = *this;}

};

class PrivateDerv:private Base
{
public:
    int f() {return protectedMem;}
    void memfcn(Base &b) {b = *this;}

};

class DervFromPubDerv:public PubDerv
{
public:
    int f() {return protectedMem;}
    void memfcn(Base &b) {b = *this;}
};

class DervFromProtectDerv:protected ProtectDerv
{
public:
    int f() {return protectedMem;}
    void memfcn(Base &b) {b = *this;}

};

class DervFromPrivateDerv:private PrivateDerv
{

};


#endif