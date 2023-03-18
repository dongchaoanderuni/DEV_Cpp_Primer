#include "Print.h"

using namespace std;

void setPairToMap(const string &str, vector<int> &vecInt, map<string, vector<int>> &strvecInt)
{
    strvecInt.insert(make_pair(str,vecInt));
    return;
}

void findKeyInMap(const string &str, map<string, vector<int>> &strvecInt, map<string, vector<int>>::iterator &findResult)
{
    findResult = strvecInt.find(str);

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

    istream_iterator<int> in(inFile), eof;
    map<string, vector<int>> strvecInt;
    string last{"ButNotLeast"};
    vector<int> vecInt(in, eof);
    map<string, vector<int>>::iterator findResult;

    setPairToMap(last, vecInt, strvecInt);

    findKeyInMap(last,strvecInt,findResult);
    
    print(cout, strvecInt);

}
