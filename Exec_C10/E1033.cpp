#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include "Variable.h"

using namespace std;

#define LegalInput (4)

int main(int argc, char* argv[])
{


    if(LegalInput != argc)
    {
        cout << __LINE__ << " input params not legal " << argc << endl;
        return -1;
    }

    ifstream inFile(argv[1]);
    ofstream outOddFile(argv[2]);
    ofstream outEvenFile(argv[3]);
    istream_iterator<int> in(inFile), eof;
    ostream_iterator<int> outOdd(outOddFile, " ");
    ostream_iterator<int> outEven(outEvenFile, " ");
    vector<int> vecInt(in, eof);
    for(auto ele:vecInt)
    {
        if(ele % 2)
        {
            outOdd = ele;
        }
        else
        {
            outEven = ele;
        }
    }

    // copy(vecInt.begin(), vecInt.end(), outOdd);
    cout << endl;

    return 0;
}
