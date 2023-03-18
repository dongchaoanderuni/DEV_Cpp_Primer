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

void showElement(vector<string> &vStr)
{
    for(auto ele:vStr)
    {
        cout << ele << " ";
    }
    cout << endl;
}

void showElement(vector<int> &vStr)
{
    for(auto ele:vStr)
    {
        cout << ele << " ";
    }
    cout << endl;
}

void showElement(list<int> &vStr)
{
    for(auto ele:vStr)
    {
        cout << ele << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    int inputInt;
    istream_iterator<int> in(cin), eof;
    ostream_iterator<int> out_iter(cout, " ");
    vector<int> vecInt(in,eof);
    sort(vecInt.begin(),vecInt.end());

    copy(vecInt.begin(),vecInt.end(), out_iter);
    cout << endl;

    return 0;
}
