#include "Print.h"
#include "StrBlob.h"
#include <cstring>
#include "HasPtr.h"


using namespace std;

#define LegalInput (2)

class numbered
{
friend void f(const numbered &s);

public:
    numbered() {seqNo++; cout << "numbered() seqNo:" << seqNo << endl;}
    numbered(const numbered &rhs) {seqNo++; cout << "numbered(const numbered &rhs) seqNo:" << seqNo << endl;}

private:
    static int seqNo;
};

int numbered::seqNo = 0;

// void f(numbered s) {cout << s.seqNo << endl;}
void f(const numbered &s) {cout << s.seqNo << endl;}


int main(int argc, char* argv[])
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);


    return 0;
}
