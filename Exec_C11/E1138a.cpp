#include "Print.h"

using namespace std;

void countWords(vector<string> &vecStr)
{
    unordered_map<string, size_t> countWords;

    sort(vecStr.begin(),vecStr.end());
    for(const auto ele:vecStr)
    {
        ++countWords[ele];
    }
    
    print(cout, countWords);

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

    countWords(vecStr);
}
