#include "Print.h"
#include "StrBlob.h"

using namespace std;

#define LegalInput (2)

int main(int argc, char* argv[])
{

    if(LegalInput != argc)
    {
        cout << __LINE__ << " input params not legal " << argc << endl;
        return -1;
    }

    ifstream inFile(argv[1]);
    if(!inFile)
    {
        cerr << "Input File parse failed." << endl;
    }

    string input;
    StrBlob strBlob;

    while(inFile >> input)
    {
        strBlob.push_back(input);
    }

    for(auto iter = strBlob.cbegin(); neq(iter,strBlob.cend()); iter.incr())
    {
        cout << iter.deref() << endl;
    }

    return 0;
    
}
