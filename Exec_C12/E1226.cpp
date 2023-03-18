#include "Print.h"
#include "StrBlob.h"
#include <cstring>

using namespace std;

#define LegalInput (2)


void newDynamicStrArray(ifstream &inFile, size_t size)
{

    if(!inFile)
    {
        cerr << "Input File parse failed." << endl;
    }

    string * const p = new string[size];
    string s;
    string *q = p;
    while((inFile >> s)
         && (q != p + size))
    {
        *q++ = s;
        // cout << s << endl;
    }
    while(p!=q)
    {
        cout << *(--q) << endl;
    }
    
    delete [] p;

    return;

}

void allocateDynamicStrArray(ifstream &inFile, size_t size)
{

    if(!inFile)
    {
        cerr << "Input File parse failed." << endl;
    }

    allocator<string> allStr;
    auto const p = allStr.allocate(size);
    auto q = p;
    string s;

    while((inFile >> s)
         && (q != p + size))
    {
        allStr.construct(q++,s);
    }


    while(p!=q)
    {
        cout << *(--q) << endl;
    }

    allStr.deallocate(p,size);

    return;

}

int main(int argc, char* argv[])
{

    if(LegalInput != argc)
    {
        cout << __LINE__ << " input params not legal " << argc << endl;
        return -1;
    }


    ifstream inFile(argv[1]);
    
    newDynamicStrArray(inFile, 10);

    cout << "Here is allocate." << endl;

    allocateDynamicStrArray(inFile, 10);

    return 0;
}
