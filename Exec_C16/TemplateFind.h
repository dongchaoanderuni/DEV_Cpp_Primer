#ifndef __TEMPLATECFIND_H__
#define __TEMPLATECFIND_H__

using namespace std;

template <typename I, typename T> 
I tempFind(I begin, I end, const T &targetValue)
{
    while((begin != end)
        &&(*begin != targetValue))
    {
        begin++;
    }
    return begin;
}

template <typename I>
void print(I result,I end)
{
    if (result != end)
    {
        cout << "Found: " << *result << '\n';
    }
    else
    {
        cout << "Not found\n";
    }

}

#endif