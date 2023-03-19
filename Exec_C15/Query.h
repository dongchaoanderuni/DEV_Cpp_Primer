#ifndef __QUERY_H__
#define __QUERY_H__

#include "TextQuery.h"
#include <string>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

using namespace std;

class Query_Base
{
friend class Query;
public:
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_Base() = default;

private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
};

class Query
{
friend Query operator~(const Query&);
friend Query operator|(const Query&, const Query&);
friend Query operator&(const Query&, const Query&);
friend ostream& operator<<(ostream &os, const Query& query);

public:
    Query(const string &);
    QueryResult eval(const TextQuery &t) const {cout << "Query: eval" << endl; return q->eval(t);} 
    string rep() const {cout << "Query: rep" << endl; return q->rep();}

private:
    Query(shared_ptr<Query_Base> query):q(query) {}
    shared_ptr<Query_Base> q;


};

ostream& operator<<(ostream &os, const Query& query)
{
    return os << query.rep();
}

class WordQuery:public Query_Base
{
friend class Query;

public:
protected:

private:
    WordQuery(const string &str):query_word(str) {cout << "WordQuery: init construct"<<endl;}
    QueryResult eval(const TextQuery &t) const {cout << "WordQuery: eval" << endl; return t.query(query_word);}
    string rep() const {cout << "WordQuery: rep" << endl; return query_word;}
    string query_word;
};

inline Query::Query(const string &str):q(new  WordQuery(str)){cout << "Query: init construct"<<endl;}

class BinaryQuery:public Query_Base
{
public:
private:
protected:
    BinaryQuery(const Query&left, const Query&right, string str):lhs(left),rhs(right),opSym(str) {cout << "BinaryQuery: init construct"<<endl;}
    string rep() const {cout << "BinaryQuery: eval" << endl; return "(" + lhs.rep()+ " " + opSym + " " + rhs.rep() + ")";}

    Query lhs;
    Query rhs;
    string opSym;

};

class AndQuery:public BinaryQuery
{
friend Query operator&(const Query&, const Query&);
public:
protected:
private:
    AndQuery(const Query& left, const Query& right):BinaryQuery(left,right,"&") {cout << "AndQuery: init construct"<<endl;}
    QueryResult eval(const TextQuery&) const;
};
inline Query operator&(const Query& lhs, const Query& rhs)
{
    return shared_ptr<Query_Base>(new AndQuery(lhs, rhs));
}

class OrQuery:public BinaryQuery
{
friend Query operator|(const Query&, const Query&);
public:
protected:
private:
    OrQuery(const Query& left, const Query& right):BinaryQuery(left,right,"|") {cout << "OrQuery: init construct"<<endl;}
    QueryResult eval(const TextQuery&) const;
};

// returns the intersection of its operands' result sets
QueryResult
AndQuery::eval(const TextQuery& text) const
{
    // virtual calls through the Query operands to get result sets for the operands
    auto left = lhs.eval(text), right = rhs.eval(text);

	// set to hold the intersection of left and right
    auto ret_lines = make_shared<set<line_no>>();  

    // writes the intersection of two ranges to a destination iterator
    // destination iterator in this call adds elements to ret
    set_intersection(left.begin(), left.end(), 
                   right.begin(), right.end(),
                   inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

// returns the union of its operands' result sets
QueryResult
OrQuery::eval(const TextQuery& text) const
{
    // virtual calls through the Query members, lhs and rhs 
	// the calls to eval return the QueryResult for each operand
    auto right = rhs.eval(text), left = lhs.eval(text);  

	// copy the line numbers from the left-hand operand into the result set
	auto ret_lines = 
	     make_shared<set<line_no>>(left.begin(), left.end());

	// insert lines from the right-hand operand
	ret_lines->insert(right.begin(), right.end());
	// return the new QueryResult representing the union of lhs and rhs
    return QueryResult(rep(), ret_lines, left.get_file());
}

inline Query operator|(const Query& lhs, const Query& rhs)
{
    return shared_ptr<Query_Base>(new OrQuery(lhs, rhs));
}

class NotQuery:public Query_Base
{
friend Query operator~(const Query &);

public:
protected:

private:
    NotQuery(const Query& q):query(q) {cout << "NotQuery: init construct"<<endl;}
    string rep() const {cout << "NotQuery: eval" << endl;  return "~()" + query.rep() + ")";}
    QueryResult eval(const TextQuery&) const;
    Query query;
};

inline Query operator~(const Query& operand)
{
    return shared_ptr<Query_Base>(new NotQuery(operand));
}

QueryResult
NotQuery::eval(const TextQuery& text) const
{
    // virtual call to eval through the Query operand 
    auto result = query.eval(text);

	// start out with an empty result set
    auto ret_lines = make_shared<set<line_no>>();

	// we have to iterate through the lines on which our operand appears
	auto beg = result.begin(), end = result.end();

    // for each line in the input file, if that line is not in result,
    // add that line number to ret_lines
	auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n) {
		// if we haven't processed all the lines in result
		// check whether this line is present
		if (beg == end || *beg != n) 
        {
			ret_lines->insert(n);  // if not in result, add this line 
        }
        else if (beg != end) 
		{
        	++beg; // otherwise get the next line number in result if there is one
        }
    }
	return QueryResult(rep(), ret_lines, result.get_file());
}

ifstream& open_file(ifstream& file, const string& filename) 
{
    file.close();
    file.clear();
    file.open(filename.c_str());
    return file;
}

TextQuery get_file(int argc, char** argv) 
{
    if (argc < 2)
        throw runtime_error("No input file specified");

    ifstream infile;
    open_file(infile, argv[1]);

    TextQuery tq;
    tq.read_file(infile);

    return tq;
}

bool get_word(string& word) 
{
    cout << "Enter a word to search for (or q to quit): ";
    cin >> word;

    if (word == "q")
    return false;

    return true;
}

bool get_words(string& word1, string& word2)
{
    cout << "Enter two words to search for, separated by space (or q to quit): ";
    cin >> word1 >> word2;

    if (word1 == "q" || word2 == "q")
    {
        return false;
    }

    return true;
}

ostream& print(ostream& output_stream, const QueryResult& qr)
{
  output_stream << qr.sought << " occurs " << qr.lines->size() << " times:" << endl;

  for (auto it = qr.begin(); it != qr.end(); ++it) 
  {
    output_stream << "\t(line " << (*it) + 1 << ") "
                  << *(qr.file->begin() + *it) << endl;
  }

  return output_stream;
}


#endif