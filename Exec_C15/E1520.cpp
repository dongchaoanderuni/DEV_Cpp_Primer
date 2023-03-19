#include "Headfile.h"
#include "BaseDerivedDerived.h"

using namespace std;

int main() {

    PubDerv d1;
    PrivateDerv d2;
    ProtectDerv d3;
    DervFromPubDerv dd1;
    DervFromPrivateDerv dd2;
    DervFromProtectDerv dd3;
    Base *p;

    p = &d1;
    // p = &d2;
    // p = &d3;
    p = &dd1;
    // p = &dd2;
    // p=  &dd3

    Base base;
    d1.memfcn(base);
    d2.memfcn(base);
    d3.memfcn(base);
    dd1.memfcn(base);
    dd3.memfcn(base);

    return 0;
}
