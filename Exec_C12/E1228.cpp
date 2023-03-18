#include "Print.h"
#include "StrBlob.h"
#include <cstring>

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
    vector<string> vecStr;
    map<string,set<int>> mapStrToIntSet;
    string line;
    int lineNo{0};

    while(inFile>>line)
    {
        istringstream ifstream(line);
        string word;
        ++lineNo;
        while(ifstream >> word)
        {
            mapStrToIntSet[word].insert(lineNo);
        }
    }



    return 0;
}
