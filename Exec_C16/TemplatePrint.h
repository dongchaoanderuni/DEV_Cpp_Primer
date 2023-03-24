#ifndef __TEMPLATEPRINT_H__
#define __TEMPLATEPRINT_H__

using namespace std;

template <typename T , unsigned N>
void print(T (&arr)[N])
{
    for(unsigned tmp = 0; tmp < N; tmp++)
    {
        cout << arr[tmp] << " ";
    }
    cout << endl;
}


#endif