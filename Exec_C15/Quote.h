#ifndef __QUOTE_H__
#define __QUOTE_H__


using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const string &book, double sales_price): bookNo(book), price(sales_price) {}
    
    string isbn() const {return bookNo;}
    virtual double net_price(size_t n) const {return n * price;}
    virtual void debug() {cout << bookNo << " " << price << endl;}

    virtual ~Quote() = default;

private:
    string bookNo;

protected:
    double price = 0.0;
};

class Disc_quote:public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const string& book, double sales_price, size_t qty, double disc): Quote(book, sales_price), quantity(qty), discount(disc) {}

    size_t count() const {return quantity;}
    double disc()  const {return discount;}

    double net_price(size_t) const = 0;

private:
    size_t quantity = 0;
    double discount = 0.0;
};


class Bulk_Quote:public Disc_quote
{
public:

    Bulk_Quote() = default;
    Bulk_Quote(const string& book, double sales_price, size_t qty, double disc):Disc_quote(book, sales_price, qty, disc) {};
    double net_price(size_t) const override;
    void debug() override;

// private:
//     size_t min_qty = 0;         /* 通过折扣政策的最低购买量 */
//     double discount = 0.0;      /* 以小数表示的折扣额 */
};

double Bulk_Quote::net_price(size_t cnt) const
{
    if(cnt > count())
    {
        return cnt * (1 - disc() ) * price;
    }
    return cnt * price;
}

inline void Bulk_Quote::debug()
{
    cout << isbn()<< " " << price << " "<< count() << " " << disc() << endl;
}

class Count_Quote:public Disc_quote
{
friend void print_total(ostream&, const Quote&, size_t);
public:

    Count_Quote() = default;
    Count_Quote(const string& book, double sales_price, size_t qty, double disc):Disc_quote(book, sales_price, qty, disc) {};
    double net_price(size_t) const override;
    void debug() override;

private:
//     size_t max_qty = 0;         /* 通过折扣政策的最低购买量 */
//     double discount = 0.0;      /* 以小数表示的折扣额 */
};

double Count_Quote::net_price(size_t cnt) const
{
    if(cnt <= count())
    {
        return cnt * (1 - disc() ) * price;
    }
    return count() * (1 - disc() ) * price + (cnt - count()) * price;
}

inline void Count_Quote::debug()
{
    cout << isbn() << " "<< price << " "<< count()  << " "<< disc() << endl;
}

void print_total(ostream& os, const Quote& item, size_t n)
{
    double ret =item.net_price(n);
    os << "ISBN: " << item.isbn() << "# sold: " << n << " total due: " << ret << endl;
}

#endif