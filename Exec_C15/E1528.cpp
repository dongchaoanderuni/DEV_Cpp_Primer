#include "Headfile.h"
#include "Quote.h"

using namespace std;

int main() 
{

    vector<Quote*> vec;
    // vec.push_back(new Quote("111-222-333", 20.0)); // Quote: constructor taking string and double
    // vec.push_back(new Bulk_Quote("000-111-222", 15.0, 10, 0.2)); // Bulk_Quote: constructor taking string, double, size_t and double
    for(size_t i = 0; i != 1; ++i)
    {
        vec.push_back(new Bulk_Quote("C++ Primer", 6, 5, 0.5));
    }
    
    double sum = 0.0;
    for (auto q : vec)
    {
        // cout << q->isbn() << ": " << q->net_price(10) << endl;
        sum +=  q->net_price(10);
    }

    cout << sum << endl;

    for (auto q : vec)
    {
        delete q;
    }

    return 0;
}