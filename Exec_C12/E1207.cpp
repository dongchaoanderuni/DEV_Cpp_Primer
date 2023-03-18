#include "Print.h"
#include "StrBlob.h"

using namespace std;

vector<int>* new_vector(void)
{
    return new (nothrow) vector<int>;
}

shared_ptr<vector<int>> shared_vector(void)
{
    return make_shared<vector<int>>();
}

void print(ostream &os, shared_ptr<vector<int>> pIntVec)
{
    for(auto ele:*pIntVec)
    {
        os << ele << endl;
    }
    return;
}

void storeIntInSharedVector(shared_ptr<vector<int>> pIntVec, ifstream &infile)
{
    int input;
    while(infile >> input)
    {
        pIntVec->push_back(input);
    }

    print(cout, pIntVec);
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

    shared_ptr<vector<int>> pIntVec = shared_vector();

    storeIntInSharedVector(pIntVec, inFile);

    return 0;
}
