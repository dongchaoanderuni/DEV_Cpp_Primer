#include "Headfile.h"
#include "Quote.h"

using namespace std;

int main() {
    Quote q("book1", 10.0);
    Bulk_Quote bq("book2", 20.0, 3, 0.1);
    Count_Quote cq("book3", 20.0, 3, 0.1);
    print_total(cout, q, 5);
    cout << endl;
    q.debug();

    print_total(cout, bq, 2);
    cout << endl;
    bq.debug();

    print_total(cout, cq, 5);
    cout << endl;
    cq.debug();

    return 0;
}
