#include "Headfile.h"
#include "TemplateDelete.h"

using namespace std;

int main()
{
    double* p = new double;
    DebugDelete d;
    d(p);

    int* ip = new int;
    DebugDelete()(ip);

    unique_ptr<int, DebugDelete> ipEins(new int, DebugDelete());
    unique_ptr<string, DebugDelete> sp(new string, DebugDelete());
    
    return 0;
}   