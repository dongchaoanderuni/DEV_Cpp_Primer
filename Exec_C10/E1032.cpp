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
        cout << __LINE__ << "input file parse failed." << endl;
        return -1;
    }

    istream_iterator<Sales_item> in(inFile), eof;
    vector<Sales_item> vecSalesItem(in, eof);

    if(vecSalesItem.empty())
    {
        cerr << "No Data." << endl;
        return -1;
    }

    sort(vecSalesItem.begin(), vecSalesItem.end(), compareIsbn);

    auto begin = vecSalesItem.begin();
    while(begin != vecSalesItem.end())
    {
        auto item = *begin;
        auto right = find_if(vecSalesItem.begin(), vecSalesItem.end(),
                                [item](const Sales_item &itemEins){return item.isbn()!=itemEins.isbn();});
        cout << accumulate(begin+1,right,item) << endl;
        begin = right;
    }

    return 0;
}
