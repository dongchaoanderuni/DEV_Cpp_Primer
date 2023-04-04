#ifndef SALES_DATAH
#define SALES_DATAH

#include <string>
#include <iostream>

using namespace std;

class Sales_data;

template <>
struct std::hash<Sales_data>;

class Sales_data 
{
friend class std::hash<Sales_data>;
friend Sales_data add(const Sales_data&, const Sales_data&);
friend ostream &print(ostream&, const Sales_data&);
friend istream &read(istream&, Sales_data&);
friend Sales_data operator+(const Sales_data&, const Sales_data&);
friend Sales_data operator-(const Sales_data&, const Sales_data&);
friend ostream& operator<<(ostream &, const Sales_data&);
friend istream& operator>>(istream &, Sales_data&);
// friend bool operator==(const  Sales_data&, const Sales_data&);
// friend bool operator!=(const Sales_data&, const Sales_data &); 

public:
    Sales_data() = default;
    Sales_data(const string &s):bookNo(s), units_sold(0), revenue(0.0) {}
    Sales_data(const string&s, unsigned n, double p):
                bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(istream &is) ;
    string isbn() const  {return bookNo;}
    // explicit operator string() const {return bookNo;}
    // explicit operator double() const {return revenue;}

    Sales_data& combine(const Sales_data&);
    Sales_data& operator+=(const Sales_data& rhs);
    Sales_data& operator-=(const Sales_data& rhs);
    Sales_data& operator=(const Sales_data&);   
    bool operator==(const Sales_data&) const;
    bool operator!=(const Sales_data &rhs) const;

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

Sales_data& Sales_data::operator=(const Sales_data& lhs)
{
    units_sold = lhs.units_sold;
    bookNo = lhs.bookNo;
    revenue = lhs.revenue;
    
    return *this;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data& Sales_data::operator-=(const Sales_data& rhs)
{
    if(bookNo == rhs.bookNo)
    {
        units_sold -= rhs.units_sold;
        revenue -= rhs.revenue;
    }

    return *this;
}

Sales_data operator-(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sum = lhs;
    if(lhs.bookNo == rhs.bookNo)
    {
        sum -= rhs;
    }
    return sum;
}


istream& operator>>(istream &is, Sales_data& item)
{
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if(is)
    {
        item.revenue = item.units_sold * price;
    }
    else
    {
        item = Sales_data();
    }

    return is;

}

ostream &operator<<(ostream &os, const Sales_data& item)
{
    os << item.isbn() << " sold " << item.units_sold << " for "
        << item.revenue << " in average " << item.avg_price();
    
    return os;
}

// bool operator==(const Sales_data&lhs, const Sales_data &rhs)
// {
//     if((lhs.bookNo == rhs.bookNo))
//     {
//         return true;
//     }
//     return false; 
// }

bool Sales_data::operator==(const Sales_data &rhs) const
{
    return ((bookNo == rhs.bookNo)
            &&(units_sold == rhs.units_sold)
            &&(revenue == rhs.revenue));
}

bool Sales_data::operator!=(const Sales_data &rhs) const
{
    return !operator==(rhs);
}

// bool operator!=(const Sales_data&lhs, const Sales_data &rhs)
// {
//     return !(lhs == rhs);
// }


ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " sold " << item.units_sold << " for "
        << item.revenue << " in average " << item.avg_price();
    
    return os;
}

#endif