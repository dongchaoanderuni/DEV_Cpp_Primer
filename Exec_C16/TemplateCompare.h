#ifndef __TEMPLATECOMPARE_H__
#define __TEMPLATECOMPARE_H__

using namespace std;

template <typename T> int compare(const T& lhs, const T& rhs)
{
    if(lhs < rhs)
    {
        return -1;
    }
    if(rhs < lhs)
    {
        return 1;
    }
    return 0;
}

#endif