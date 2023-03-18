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
#include <functional>
#include <map>          
#include <set>         
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

void showMap(map<string, size_t> &showMap)
{
    for(const auto ele:showMap)
    {
        cout << ele.first << " occurs " << ele.second
        << ((ele.second > 1)?" times.":"time") << endl;
    }
}


void countWords(vector<string> &vecStr)
{
    map<string, size_t> countWords;
    sort(vecStr.begin(),vecStr.end());
    for(const auto ele:vecStr)
    {
        ++countWords[ele];
    }
    
    showMap(countWords);

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
