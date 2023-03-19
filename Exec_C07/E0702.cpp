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

    string isbn() const  {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
};

Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);

double Sales_data::avg_price() const
{
    if(units_sold)
    {
        return revenue/units_sold;
    }
    return 0;
}

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold  += rhs.units_sold;
    revenue     += rhs.revenue;
    return *this;
}


int main()
{
    Sales_data total;

    if(cin>>total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;
        while(cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
        {
            if(total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                cout << total.isbn() << " sold " << total.units_sold << " for " << total.revenue << endl; 
                total = trans;
            }
        }
        cout << total.isbn() << " sold " << total.units_sold << " for " << total.revenue << endl; 
    }

    return 0;
}
