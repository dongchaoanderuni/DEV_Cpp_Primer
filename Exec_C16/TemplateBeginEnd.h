#ifndef __TEMPLATEBEGINEND_H__
#define __TEMPLATEBEGINEND_H__

using namespace std;

template <typename T ,unsigned N>
pair<T*,T*> tempFindBeginAndEnd(T (&arr)[N])
{
    T *begin = &arr[0];
    T *end = &arr[N];
    return pair<T*, T*>(begin, end);
}

#endif