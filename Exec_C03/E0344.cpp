#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string.h>

using namespace std;
using int_array = int[4];

int main()
{
    constexpr int row_size = 3;
    constexpr int col_size = 4;
    int ia[row_size][col_size];
    int value{0};

    for(auto &row:ia)
    {
        for(auto &col:row)
        {
            col = value;
            value++;
        }
    }

    /* METHOD_EINS */
    for(int_array &row:ia)
    {
        for(int &col:row)
        {
            cout << col << ' ';
        }
        cout << endl;
    }
    cout << endl;

    /* METHOD_TWO */
    for(int i = 0; i < row_size; i++)
    {
        for(int j = 0; j < col_size; j++)
        {
            cout << ia[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;


    /* METHOD_THREE */
    for(int_array *p = ia; p < ia + row_size ; ++p)
    {
        for(int *q = *p; q < *p + col_size; ++q)
        {
            cout << *q << ' ';
        }
        cout << endl;
    }
    cout << endl;



    return 0;
}