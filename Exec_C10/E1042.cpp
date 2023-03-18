#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <algorithm>
#include <numeric>
#include <iterator>
#include "Variable.h"

using namespace std;

void showElement(vector<string> &vStr)
{
    for(auto ele:vStr)
    {
        cout << ele << " ";
    }
    cout << endl;
}

void showElement(list<string> &listStr)
{
    ostream_iterator<string> out(cout, " ");

    copy(listStr.begin(),listStr.end(),out);
    cout << endl;

    return;
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void elimDups(vector<string> vStr)
{
    sort(vStr.begin(), vStr.end());
    showElement(vStr);

    auto end_unique = unique(vStr.begin(), vStr.end());
    vStr.erase(end_unique, vStr.end());
    showElement(vStr);

    sort(vStr.begin(), vStr.end(), isShorter);
    showElement(vStr);

    stable_sort(vStr.begin(), vStr.end(), isShorter);
    showElement(vStr);

}

void elimDups(list<string> listStr)
{
    // sort(vStr.begin(), vStr.end());
    listStr.sort();
    showElement(listStr);

    listStr.unique();
    showElement(listStr);

    listStr.sort(isShorter);
    showElement(listStr);
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
    list<string> listStr(in, eof);

    elimDups(listStr);

}
