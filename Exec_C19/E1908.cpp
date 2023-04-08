#include "Headfile.h"
#include <cstdlib>
#include <typeinfo>

using namespace std;

class Query_Base
{
public:
    Query_Base() {}
    virtual ~Query_Base() {}
};

class BinaryQuery:public Query_Base
{
public:
    BinaryQuery() {}
    virtual ~BinaryQuery() {}
};

class AndQuery:public BinaryQuery
{
public:
    AndQuery() {}
    virtual ~AndQuery() {}
};


int main() 
{

    Query_Base* pa = new Query_Base;
    Query_Base* pb = new Query_Base;

    if(typeid(*pa) == typeid(*pb))
    {
        cout << "equal type: " << typeid(*pa).name() << endl;
    }

    if(typeid(Query_Base) == typeid(*pa))
    {
        cout << "Type: " << typeid(Query_Base).name() << endl;
    }
}
