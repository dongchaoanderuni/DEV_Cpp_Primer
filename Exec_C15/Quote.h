#ifndef __QUOTE_H__
#define __QUOTE_H__


using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const string &book, double sales_price): bookNo(book), price(sales_price) {cout << "Quote: Init constructor" << endl;}
    Quote(const Quote&lhs):bookNo(lhs.bookNo),price(lhs.price) {cout << "Quote: copy constructor" << endl;}
    Quote(Quote &&lhs):bookNo(std::move(lhs.bookNo)),price(std::move(lhs.price)){cout << "Quote: move constructor" << endl;}
    
    virtual Quote* clone() const & {return new Quote(*this);}
    virtual Quote* clone() && {return new Quote(std::move(*this));}
    
    Quote& operator=(const Quote&lhs){bookNo = lhs.bookNo; price = lhs.price; cout << "Quote: copy assignment operator" << endl; return *this;}
    Quote& operator=(Quote&&lhs){bookNo = std::move(lhs.bookNo); price = std::move(lhs.price); cout << "Quote: move assignemnt operator" << endl;  return *this;}

    string isbn() const {return bookNo;}
    virtual double net_price(size_t n) const {return n * price;}
    virtual void debug() {cout << bookNo << " " << price << endl;}

    virtual ~Quote(){cout <<"Quote: deconstructor" << endl;}

private:
    string bookNo;

protected:
    double price = 0.0;
};

class Disc_quote:public Quote
{
public:
    // Disc_quote() = default;
    Disc_quote(const string& book="", double sales_price=0.0, size_t qty=0, double disc=0.0): Quote(book, sales_price), quantity(qty), discount(disc) {cout << "Disc_quote: Init constructor" << endl;}
    Disc_quote(const Disc_quote &lhs):Quote(lhs){cout <<"Disc_quote: copy constructor" << endl;}
    Disc_quote(Disc_quote &&lhs):Quote(std::move(lhs)){cout << "Disc_quote: move constructor" << endl;}
    Disc_quote& operator=(const Disc_quote& lhs){Quote::operator=(lhs); quantity =  lhs.quantity; discount = lhs.quantity; cout << "Disc_quote: copy assignment operator" << endl; return *this;}
    Disc_quote& operator=(Disc_quote&& lhs){quantity = std::move(lhs.quantity); discount = std::move(lhs.discount); Quote::operator=(std::move(lhs)); cout << "Disc_quote: move assignemnt operator" << endl; return *this;}

    size_t count() const {return quantity;}
    double disc()  const {return discount;}
    double net_price(size_t) const = 0;

    ~Disc_quote() {cout << "Disc_quote: deconstructor" << endl;}

private:
    size_t quantity = 0;
    double discount = 0.0;
};


class Bulk_Quote:public Disc_quote
{
public:

    // Bulk_Quote() = default;
    // Bulk_Quote(const string& book, double sales_price, size_t qty, double disc):Disc_quote(book, sales_price, qty, disc) {cout << "Bulk_Quote: Init constructor" << endl;}
    Bulk_Quote(const Bulk_Quote &lhs):Disc_quote(lhs)    {cout <<"Bulk_Quote: copy constructor" << endl;};
    Bulk_Quote(Bulk_Quote &&lhs):Disc_quote(std::move(lhs))     {cout << "Bulk_Quote: move constructor" << endl;}
    Bulk_Quote* clone() const & override;
    Bulk_Quote* clone() && override;
    
    Bulk_Quote& operator=(const Bulk_Quote& lhs)    {Disc_quote::operator=(lhs); cout << "Bulk_Quote: copy assignment operator" << endl;  return *this;}
    Bulk_Quote& operator=(Bulk_Quote&& lhs) {Disc_quote::operator=(std::move(lhs)); cout << "Bulk_Quote: move assignemnt operator" << endl;  return *this;}
    double net_price(size_t) const override;
    void debug() override;

    using Disc_quote::Disc_quote;

    ~Bulk_Quote() {cout << "Bulk_Quote: deconstructor" << endl;};

// private:
//     size_t min_qty = 0;         /* 通过折扣政策的最低购买量 */
//     double discount = 0.0;      /* 以小数表示的折扣额 */
};

Bulk_Quote* Bulk_Quote::clone() const &
{
    return new Bulk_Quote(*this);
}

Bulk_Quote* Bulk_Quote::clone() &&
{
    return new Bulk_Quote(std::move(*this));
}

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
friend double print_total(ostream&, const Quote&, size_t);
public:

    Count_Quote() = default;
    Count_Quote(const string& book, double sales_price, size_t qty, double disc):Disc_quote(book, sales_price, qty, disc) {cout << "Count_Quote: Init constructor" << endl;}
    Count_Quote(const Count_Quote &lhs):Disc_quote(lhs)    {cout <<"Count_Quote: copy constructor" << endl;};
    Count_Quote(Count_Quote &&lhs):Disc_quote(std::move(lhs))     {cout << "Count_Quote: move constructor" << endl;}
    Count_Quote* clone() const & override;
    Count_Quote* clone() && override;
    Count_Quote& operator=(const Count_Quote& lhs)    {Disc_quote::operator=(lhs); cout << "Count_Quote: copy assignment operator" << endl;  return *this;}
    Count_Quote& operator=(Count_Quote&& lhs) {Disc_quote::operator=(std::move(lhs)); cout << "Count_Quote: move assignemnt operator" << endl;  return *this;}
    double net_price(size_t) const override;
    void debug() override;


    ~Count_Quote() {cout << "Count_Quote: deconstructor" << endl;};

private:
//     size_t max_qty = 0;         /* 通过折扣政策的最低购买量 */
//     double discount = 0.0;      /* 以小数表示的折扣额 */
};

Count_Quote* Count_Quote::clone() const &
{
    return new Count_Quote(*this);
}

Count_Quote* Count_Quote::clone() &&
{
    return new Count_Quote(std::move(*this));
}


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

double print_total(ostream& os, const Quote& item, size_t n)
{
    double ret =item.net_price(n);
    os << "ISBN: " << item.isbn() << "# sold: " << n << " total due: " << ret << endl;
    return ret;
}

#endif