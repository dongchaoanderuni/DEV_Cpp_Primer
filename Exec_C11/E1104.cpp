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

bool isExcludeWord(const string &str)
{
    set<string> excludeWords{"The","the","But","but","And","and","Or","or","An","an","A","a"};

    if(excludeWords.find(str) == excludeWords.end())
    {
        return false;
    }
    return true;
}

void setValuewordToSetPro(const string &keyStr, const string &valueStr, map<string,set<string>> &wordexamplePro)
{
    if(wordexamplePro.find(keyStr) != wordexamplePro.end())
    {
        wordexamplePro[keyStr].insert(valueStr);
    }

    cerr << "Not Good." << endl;

    return;
}

void setValueSetPro(const string &keyStr, set<string> &setStr, map<string,set<string>> &wordexamplePro)
{
    if(wordexamplePro.find(keyStr) == wordexamplePro.end())
    {
        wordexamplePro[keyStr] = setStr;
    }
    return;
}

void getProcessedWord(string &keyStr, map<string,set<string>> &wordexamplePro)
{
    for(auto ele:wordexamplePro)
    {
        if(ele.second.find(keyStr)!=ele.second.end())
        {
            keyStr = ele.first;
        }
    }
    return;
}

void setWordexamplePro(map<string,set<string>> &wordexamplePro)
{
    set<string> sameWordExample{"Example","example","examples","examples.","examples,"};
    setValueSetPro("example", sameWordExample,wordexamplePro);
}

void countWords(vector<string> &vecStr, map<string,set<string>> &wordexamplePro)
{
    map<string, size_t> countWords;
    sort(vecStr.begin(),vecStr.end());
    for(auto ele:vecStr)
    {
        if(!isExcludeWord(ele))
        {
            getProcessedWord(ele, wordexamplePro);
            ++countWords[ele];
        }
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
    map<string,set<string>> wordexamplePro;
    vector<string> vecStr(in,eof);

    setWordexamplePro(wordexamplePro);


    countWords(vecStr,wordexamplePro);
}
