#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>
#include "Sales_data.h"

int main()
{
    Sales_data total;

    if(read(cin, total))
    {
        Sales_data trans;
        while(read(cin,trans))
        {
            if(total.isbn() == trans.isbn())
            {
                total = add(total,trans);
            }
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total)<< endl;
    }

    return 0;
}
