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
#include "Sales_item.h"

using namespace std;

#define LegalInput (2)

// inline bool compareIsbn(Sales_item &itemEins, Sales_item &itemZwei)
// {
//     return itemEins.isbn() == itemZwei.isbn();
// }

int main(int argc, char* argv[])
{

    if(LegalInput != argc)
    {
        cout << __LINE__ << " input params not legal " << argc << endl;
        return -1;
    }

    ifstream inFile(argv[1]);
    if(!inFile)
    {
        cerr << "Input File parse failed." << endl;
    }

    istream_iterator<int> in(inFile), eof;
    list<int> listInt(in, eof);
    ostream_iterator<int> out(cout, " ");

    // for(auto rbegin = vecInt.crbegin(); rbegin != vecInt.crend(); ++crbegin)
    
    auto lastPos = find(listInt.crbegin(),listInt.crend(),3);
    lastPos++;
    int pos = 1;
    for(auto iter = listInt.begin(); iter != lastPos.base(); ++iter, ++pos);

    if(pos <= listInt.size())
    {
        cout << pos << endl;
    }
    else
    {
        cout << "No such element." << endl;
    }


    return 0;
}
