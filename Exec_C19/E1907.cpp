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

    Query_Base *pa = new Query_Base;
    try
    {
        AndQuery &c = dynamic_cast<AndQuery&> (*pa);
    }
    catch(std::bad_cast &bc)
    {
        cout << "dynamic_cast failed.\n" << endl;
    }
    return 0;
}
