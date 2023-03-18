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
#include <map>          
#include <set>         
#include "Variable.h"
#include "Sales_item.h"

using namespace std;

#define LegalInput (2)

int main(int argc, char* argv[])
{
    typedef bool (*pf)(const Sales_item&, const Sales_item&);
    multiset<Sales_item, pf> bookStore(compareIsbn);
    multiset<Sales_item, pf>::const_iterator begin = bookStore.begin();

    return 0;
}
