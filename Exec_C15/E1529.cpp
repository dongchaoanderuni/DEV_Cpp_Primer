#include "Headfile.h"
#include "Quote.h"
#include "Basket.h"

using namespace std;

int main() 
{
    vector<shared_ptr<Quote>> vec_sp;
    // vec_sp.push_back(make_shared<Quote>("111-222-333", 20.0)); // Quote: constructor taking string and double
    // vec_sp.push_back(make_shared<Bulk_Quote>("000-111-222", 15.0, 10, 0.2)); // Bulk_Quote: constructor taking string, double, size_t and double    
    double sum = 0.0;
    
    for(size_t i = 0; i != 10; ++i)
    {
        vec_sp.push_back(make_shared<Bulk_Quote>("C++ Primer", 6, 5, 0.5));
    }

    for (auto sp : vec_sp)
    {
        cout << sp->isbn() << ": " << sp->net_price(10) << endl;
    }
    for (auto q : vec_sp)
    {
        sum +=  q->net_price(10);
    }
    cout << sum << endl;

    cout << "Destroying the vector of shared_ptr<Quote>..." << endl;

    return 0;
}

