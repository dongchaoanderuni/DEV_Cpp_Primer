#include "Print.h"
#include "StrBlob.h"

using namespace std;

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

    vector<int> *pIntVec = new vector<int>;

    storeIntInVector(pIntVec, inFile);

    delete pIntVec;


    return 0;
}
