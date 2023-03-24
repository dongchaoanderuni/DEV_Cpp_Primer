#include "Headfile.h"
#include "TemplateCompare.h"
#include "Sales_data.h"

using namespace std;

int main() 
{
    Sales_data lhs;
    Sales_data rhs;
    compare(lhs, rhs);

    return 0;
}
