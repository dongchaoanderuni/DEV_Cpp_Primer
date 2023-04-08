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

    Query_Base* queryBase = new Query_Base;
    if(NULL != dynamic_cast<AndQuery*>(queryBase))
    {
        cout << "Success.\n" << endl;
    }
    else
    {
        cout << "Failed.\n" << endl;
    }
    return 0;
}
