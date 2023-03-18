#ifndef PTRSTRBLOBPTR_H
#define PTRSTRBLOBPTR_H

#include "StrBlobPtr.h"

using namespace std;

class StrBlobPtr;

class PtrStrBlobPtr
{
public:

    PtrStrBlobPtr(StrBlobPtr* StrBlobPtr=nullptr):pStrBlobPtr(StrBlobPtr) {}
    StrBlobPtr* operator*() const {return pStrBlobPtr;}
    StrBlobPtr* operator->() const {return pStrBlobPtr;}

private:
    StrBlobPtr* pStrBlobPtr;
};


#endif

