

#include "Headfile.h"
#include "Quote.h"

using namespace std;

int main() 
{
    Disc_quote disc;

    // main.cpp:22:16: error: variable type 'Disc_quote' is an abstract class
    //     Disc_quote disc;
    //                ^
    // ./Quote.h:35:12: note: unimplemented pure virtual method 'net_price' in 'Disc_quote'
    //     double net_price(size_t) const = 0;
    //            ^
    // 1 error generated.

    return 0;
}
