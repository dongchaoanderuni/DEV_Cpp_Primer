#ifndef PRINTREDEFINED_H
// we're here only if SALESITEM_H has not yet been defined 
#define PRINTREDEFINED_H

#include "Headfile.h"

using namespace std;

void print(ostream &os, vector<string> &vStr)
{
    for(auto ele:vStr)
    {
        os << ele << " ";
    }
    os << endl;
    
    return;
}

void print(ostream &os, list<string> &listStr)
{
    ostream_iterator<string> out(os, " ");

    copy(listStr.begin(),listStr.end(),out);
    os << endl;

    return;
}

void print(ostream &os, map<string, size_t> &showMap)
{
    for(const auto ele:showMap)
    {
        os << ele.first << " occurs " << ele.second
        << ((ele.second > 1)?" times.":" time.") << endl;
    }

    return;
}

void print(ostream &os, unordered_map<string, size_t> &showMap)
{
    for(const auto ele:showMap)
    {
        os << ele.first << " occurs " << ele.second
        << ((ele.second > 1)?" times.":" time.") << endl;
    }

    return;
}


void print(ostream &os, map<string, vector<int>> &show)
{
    for(auto &ele:show)
    {
        for(auto jele:ele.second)
        {
            os << ele.first << " " << jele << " " << endl;
        }
    }

    return;
}

void print(ostream &os, multimap<string, string> &show)
{
    for(auto ele:show)
    {
        os << ele.first << " : " << ele.second << endl;

    }

    return;
}


#endif