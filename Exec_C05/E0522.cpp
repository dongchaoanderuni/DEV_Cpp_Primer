#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

#define targetCount (2)

int get_size()
{
    return 1;
}

int main()
{
// begin:
//     int size = get_size();
//     if(size <= 0)
//     {
//         goto begin;
//     }

    int size;
    do
    {
        size = get_size(); 
    }while(size <= 0);

    return 0;
}