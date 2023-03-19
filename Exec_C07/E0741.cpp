#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>
// #include "Sales_data.h"


using namespace std;

class Sales_data 
{
friend Sales_data add(const Sales_data&, const Sales_data&);
friend ostream &print(ostream&, const Sales_data&);
friend istream &read(istream&, Sales_data&);

public:
    Sales_data(const string&s, unsigned n, double p):
                bookNo(s), units_sold(n), revenue(p*n) {cout << "Params:3\t";}
    Sales_data():Sales_data("",0,0) {cout << "Params:0\t";}
    Sales_data(const string &s):Sales_data(s,0,0) {cout << "Params:1\t";}
    Sales_data(istream &is):Sales_data("",0,0) {cout << "Params:istream\t"; read(is, *this);}

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

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " sold " << item.units_sold << " for "
        << item.revenue << " in average " << item.avg_price();
    
    return os;
}


int main()
{
    Sales_data total(cin);
    Sales_data totalDrei;
    Sales_data totalEins = {"abc", 3,3};
    Sales_data totalZwei("abc");


    cout << endl;
    // if(cin)
    // {            
    //     Sales_data trans;
    //     while(read(cin,trans))
    //     {
    //         if(total.isbn() == trans.isbn())
    //         {
    //             total = add(total,trans);
    //         }
    //         else
    //         {
    //             print(cout, total) << endl;
    //             total = trans;
    //         }
    //     }
    //     print(cout, total)<< endl;
    // }

    return 0;
}
