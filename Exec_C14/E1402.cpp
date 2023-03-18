#include "Print.h"
#include <cstring>
#include "Sales_data.h"

using namespace std;

#define LegalInput (2)

int main()
{
    Sales_data lhs("a", 100, 5);
    Sales_data rhs("a", 10,  5);

    lhs+rhs;

    cout << lhs << endl;

    return 0;
}
