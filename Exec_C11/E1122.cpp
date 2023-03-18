#include "Print.h"

using namespace std;


void setMultiMap(vector<string> &vecStr, multimap<string,string> &multimap, const string &lastName="Christoph")
{
    for(auto ele:vecStr)
    {
        multimap.insert(make_pair(lastName,ele));
    }
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

    istream_iterator<string> in(inFile), eof;
    vector<string> vecStr(in,eof);
    string lastName;
    multimap<string,string> familyTree;

    setMultiMap(vecStr, familyTree);
    print(cout, familyTree);

    return 0;
}
