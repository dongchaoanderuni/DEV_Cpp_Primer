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

    return;
}

void showMap(map<string,vector<string>> &showMap)
{
    // ostream_iterator<string> out(cout, " ");

    for(const auto &ele:showMap)
    {
        for(const auto jele:ele.second)
        {
            cout << jele << " " << ele.first << endl;
        }
    }

    return;
}

void print(ostream &os, map<string, vector<pair<string,string>>> &familyTreePro)
{
    for(auto &ele:familyTreePro)
    {
        for(auto jele:ele.second)
        {
            os <<jele.first << " " << ele.first << " was born in " << jele.second  << endl;
        }
    }
    return ;
}

void setNewMember(const string &firstName, map<string, vector<string>> &familyTree, const string &LastName="Christoph")
{
    if(familyTree.find(LastName) != familyTree.end())
    {
        familyTree[LastName].push_back(firstName);

        return;
    }

    cerr << "Not find matched family group for LastName: " << LastName << ". Please create first." << endl;

    return;
}

void setFullName(const string &LastName, vector<string> &FirstNames, map<string,vector<string>> &familyTree)
{
    if(familyTree.find(LastName) == familyTree.end())
    {
        familyTree[LastName] = FirstNames;
        showMap(familyTree);
    }

    return;
}

void setFirstNameAndBirthDay(const string &firstName, const string &birthday, map<string, vector<pair<string,string>>> &familyTreePro, const string &lastName="Christoph")
{
    if(familyTreePro.find(lastName) == familyTreePro.end())
    {
        familyTreePro[lastName].push_back(make_pair(firstName,birthday));
    }
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
    string lastName{"Christoph"};
    map<string,vector<string>> familyTree;
    map<string, vector<pair<string,string>>> familyTreePro;

    // setFullName(lastName, vecStr, familyTree);

    setFirstNameAndBirthDay("Chandler", "1988-01-29",familyTreePro,lastName);
    print(cout, familyTreePro);

    // setNewMember("Chandler", familyTree);

    // setNewMember("Chandler", familyTree, "Bean");

    return 0;
}
