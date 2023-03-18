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
#include <utility>      
#include "Variable.h"
#include "Sales_item.h"

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

void print(ostream &os, vector<pair<string, int>> &vecPair)
{
    for(auto ele:vecPair)
    {
        os << ele.first << " : " << ele.second << " ";
    }
    os << endl;

    return ;
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


void setPairintoVector(vector<string>& vecStr, vector<int> &vecInt, vector<pair<string, int>> &vecPair)
{
    if(vecStr.empty()||vecInt.empty())
    {
        return;
    }

    auto beginStr = vecStr.cbegin();
    auto beginInt = vecInt.cbegin();
    if(vecStr.size() <= vecInt.size())
    {   
        for(;beginStr != vecStr.cend(); ++beginStr, ++ beginInt)
        {
            // vecPair.push_back(make_pair(*beginStr,*beginInt));
            // vecPair.push_back(pair<string, int>(*beginStr, *beginInt));
            vecPair.push_back({*beginStr, *beginInt});

        }
    }
    else
    {
        for(;beginInt != vecInt.cend(); ++beginStr, ++ beginInt)
        {
            // vecPair.push_back(make_pair(*beginStr,*beginInt));
            // vecPair.push_back(pair<string, int>(*beginStr, *beginInt));
            vecPair.push_back({*beginStr, *beginInt});
        }
    }
    return;
}


#define LegalInput (3)

int main(int argc, char* argv[])
{

    if(LegalInput != argc)
    {
        cout << __LINE__ << " input params not legal " << argc << endl;
        return -1;
    }

    ifstream inStrFile(argv[1]);
    ifstream inIntFile(argv[2]);
    if(!inStrFile || !inIntFile)
    {
        cerr << "Input File parse failed." << endl;
    }

    istream_iterator<string> inStr(inStrFile), eofStr;
    istream_iterator<int> inInt(inIntFile), eofInt;

    vector<string> vecStr(inStr, eofStr);
    vector<int>    vecInt(inInt, eofInt);

    vector<pair<string, int>> vecPair;

    setPairintoVector(vecStr,vecInt,vecPair);

    print(cout, vecPair);

    return 0;
}

