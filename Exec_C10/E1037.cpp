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
    vector<int> vecInt(in, eof);
    ostream_iterator<int> out(cout, " ");
    list<int> listIntZwei;

    /* Method Eins: */
    // copy(vecInt.cbegin()+2, vecInt.cbegin()+7,front_inserter(listIntZwei));

    /* Method Zwei: */
    copy(vecInt.crbegin()+3,vecInt.crend()-2, back_inserter(listIntZwei));

    copy(listIntZwei.begin(), listIntZwei.end(),out);
    // copy(vecInt.begin(), vecInt.end(),out);
    cout << endl;

    return 0;
}
