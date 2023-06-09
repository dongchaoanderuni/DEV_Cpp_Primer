#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

struct Sales_data 
{
    string bookNo;
    unsigned units_sold{0};
    double revenue{0.0};
};

int main()
{
    Sales_data total;

    if(cin>>total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;
        while(cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
        {
            if(total.bookNo == trans.bookNo)
            {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else
            {
                cout << total.bookNo << " sold " << total.units_sold << " for " << total.revenue << endl; 
                total = trans;
            }
        }
        cout << total.bookNo << " sold " << total.units_sold << " for " << total.revenue << endl; 
    }

    return 0;
}
