#ifndef __QUERYRESULT_H__
// we're here only if SALESITEM_H has not yet been defined 
#define __QUERYRESULT_H__

#include "Headfile.h"

using namespace std;

class QueryResult
{
friend ostream& print(ostream &os, const QueryResult&);
public:
	typedef vector<string>::size_type lineNo;
    typedef set<lineNo>::const_iterator lineIter;
    QueryResult(string &str, 
                    shared_ptr<set<lineNo>> pSetLineNo,
                    shared_ptr<vector<string>> vecStr):
                str(str), lines(pSetLineNo), vecStr(vecStr) {}
    set<lineNo>::size_type size() const {return lines->size();}
    lineIter begin() const {return lines->cbegin();}
    lineIter end() const {return lines->cend();}
    shared_ptr<vector<string>> getVecStr() {return vecStr;}

private:
    string str;
    shared_ptr<set<lineNo>> lines;
    shared_ptr<vector<string>> vecStr;
};

ostream &print(std::ostream& os, const QueryResult& qs)
{
    os << qs.str << " occurs "<< qs.size()  
        << ((qs.size()> 1)?" times.":"time") << endl;

    for(auto num : *qs.lines)
    {
        cout << "\t(line " << num +1 << ")" << *(qs.vecStr->begin()+num) << endl;
    }
    return os;
}

#endif
