#ifndef __TEXTQUERY_H__
// we're here only if SALESITEM_H has not yet been defined 
#define __TEXTQUERY_H__

#include "Headfile.h"
#include "QueryResult.h"
#include "StrVec.h"


using namespace std;

class QueryResult;

class TextQuery
{
friend QueryResult;
friend void runQueries(ifstream &inFile);
public:
    using lineNo = vector<string>::size_type;
    TextQuery(ifstream &inFile);
    QueryResult query(string &) const;
    void display_map();
private:
    shared_ptr<StrVec> vecStr ;
    map<string, shared_ptr<set<lineNo>>> mapStrToLineNoSets;
    static string cleanup_str(const string&);
    // vector<string> lineStr;
    // map<string, set<int>> mapStrToLineNoSets; 
};

string TextQuery::cleanup_str(const string&word)
{
    string ret;
    for(auto iter = word.begin();iter !=word.end(); ++iter)
    {
        if(!ispunct(*iter))
        {
            ret +=tolower(*iter);
        }
    }

    return ret;
}

TextQuery::TextQuery(ifstream &inFile):vecStr(new StrVec)
{
    string line;
    while(getline(inFile, line))
    {
        istringstream stream(line);
        string word;
        int lineSeqNo = vecStr->size()-1;
        vecStr->push_back(line);
        while(stream >> word)
        {
            word = cleanup_str(word);
            auto &lines = mapStrToLineNoSets[word];
            if(!lines)
            {
                lines.reset(new set<lineNo>);
            }
            lines->insert(lineSeqNo);
        }
    }
}

QueryResult TextQuery::query(string &str) const 
{
    static shared_ptr<set<lineNo>> nodata(new set<lineNo>);

    auto iter = mapStrToLineNoSets.find(cleanup_str(str));

    if(iter == mapStrToLineNoSets.end())
    {
        return QueryResult(str, nodata, vecStr);
    }
    return QueryResult(str, iter->second,vecStr);
}

void runQueries(ifstream &inFile)
{
    TextQuery tq(inFile);
    while(true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if(!(cin >> s)
            ||( s == "q"))
        {
            break;
        }
        print(cout, tq.query(s)) << endl;
    }

    return;
}

// debugging routine, not covered in the book
void TextQuery::display_map()
{
    auto iter = mapStrToLineNoSets.cbegin(), iter_end = mapStrToLineNoSets.cend();

    // for each word in the map
    for ( ; iter != iter_end; ++iter) {
        cout << "word: " << iter->first << " {";

        // fetch location vector as a const reference to avoid copying it
        auto text_locs = iter->second;
        auto loc_iter = text_locs->cbegin(),
                        loc_iter_end = text_locs->cend();

        // print all line numbers for this word
        while (loc_iter != loc_iter_end)
        {
            cout << *loc_iter;

            if (++loc_iter != loc_iter_end)
                 cout << ", ";

         }

         cout << "}\n";  // end list of output this word
    }
    cout << endl;  // finished printing entire map
}

#endif