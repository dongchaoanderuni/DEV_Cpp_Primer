#ifndef SALES_DATAH
#define SALES_DATAH

#include <string>
#include <iostream>

using namespace std;

class Sales_data 
{
friend Sales_data add(const Sales_data&, const Sales_data&);
friend ostream &print(ostream&, const Sales_data&);
friend istream &read(istream&, Sales_data&);

public:
    Sales_data() = default;
    Sales_data(string &s):bookNo(s), units_sold(0), revenue(0.0) {}
    Sales_data(const string&s, unsigned n, double p):
                bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(istream &is) ;

    string isbn() const  {return bookNo;}
    Sales_data& combine(const Sales_data&);

private:
    double avg_price() const {return units_sold?revenue/units_sold:0; }
    string bookNo;
    unsigned units_sold{0};
    double revenue{0.0};
};

Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold  += rhs.units_sold;
    revenue     += rhs.revenue;
    return *this;
}

Sales_data::Sales_data(istream &is)
{
    read(is,*this);
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " sold " << item.units_sold << " for "
        << item.revenue << " in average " << item.avg_price();
    
    return os;
}

#endif