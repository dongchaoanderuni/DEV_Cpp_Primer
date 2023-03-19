#include "Headfile.h"
#include "OverloadSearch.h"

using namespace std;

int main() {

    Base bobj;
    DEins dEinsObj;
    D2 d2obj;

    Base *bpEins = &bobj;
    Base *bp2 = &d1obj;
    Base *np3 = &d2obj;

    bpEins->fcn();
    bp2->fcn();
    bp3->fcn();

    D1 *pdEins = &d1obj;
    D2 *pd2 = &d2obj;

    pdEins->f2();
    pd2->f2();

    return 0;
}
