#ifndef __BASKET_H__
#define __BASKET_H__

#include <set>         

using namespace std;

class Basket
{
public:
    void add_item(const shared_ptr<Quote> &sale) {items.insert(sale);}
    void add_item(const Quote& sale) {items.insert(shared_ptr<Quote>(sale.clone()));}
    void add_item(Quote && sale) {items.insert(shared_ptr<Quote>(std::move(sale).clone()));;}
    double total_receipt(ostream &) const;

protected:

private:
    static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs) {return lhs->isbn() < rhs->isbn();}
    multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};

};

double Basket::total_receipt(ostream& os) const
{
    double sum = 0.0;
    for(auto iter =  items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
    {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << endl;

    return sum;
}

#endif