#include "Print.h"
#include "StrBlob.h"

using namespace std;

vector<int>* new_vector(void)
{
    return new (nothrow) vector<int>;
}

void storeIntInVector(vector<int> *pIntVec, ifstream &infile)
{
    int input;
    while(infile >> input)
    {
        pIntVec->push_back(input);
    }

    print(cout, pIntVec);

    return;
}


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

    vector<int> *pIntVec = new_vector();
    if(!pIntVec)
    {
        cout << "New Malloc Failed" << endl;
        return -1;
    }

    storeIntInVector(pIntVec, inFile);

    delete pIntVec;
    pIntVec = nullptr;

    return 0;
}
