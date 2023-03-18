#include "Print.h"
#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"
#include <cstring>


using namespace std;

#define LegalInput (2)

int main(int argc, char* argv[])
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << "SizeOf b2: " << b2.size() << endl;
        cout << "FirstElement of b2: " << b2.front() << " LastElemnt: " << b2.back() << endl;
    }

    cout << "SizeOf b1: " << b1.size() << endl;
    cout << "FirstElement of b1: " << b1.front() << " LastElemnt: " << b1.back() << endl;

    StrBlob b3 = b1;
    b3.push_back("next");
    cout << "SizeOf b3: " << b3.size() << endl;
    cout << "FirstElement of b3: " << b3.front() << " LastElemnt: " << b3.back() << endl;

    cout << "SizeOf b1: " << b1.size() << endl;
    cout << "FirstElement of b1: " << b1.front() << " LastElemnt: " << b1.back() << endl;

    return 0;
}
