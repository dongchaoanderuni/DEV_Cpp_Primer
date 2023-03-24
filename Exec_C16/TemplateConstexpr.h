#ifndef __TEMPLATECONSTEXPR_H__
#define __TEMPLATECONSTEXPR_H__

using namespace std;

template <typename T, size_t N>
constexpr int arrSize(const T (&arr)[N])
{
    return N;
}

template <typename T , size_t N>
void print(const T (&arr)[N])
{
    for(size_t tmp = 0; tmp < arrSize(arr); tmp++)
    {
        cout << arr[tmp] << " ";
    }
    cout << endl;
}

#endif