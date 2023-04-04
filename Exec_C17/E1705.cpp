#include "Headfile.h"
#include "Sales_data.h"

using namespace std;

typedef tuple<vector<Sales_data>::size_type, 
                vector<Sales_data>::const_iterator, 
                vector<Sales_data>::const_iterator> matches;

bool compareIsbn(const Sales_data& lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

vector<pair<index,pair<vecotr<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>>>
findBook(const vector<vector<Sales_data>> &files, const string &book)
{
    vector<matches> ret;
    size index = 0;
    for(size_t index = 0; const auto& file:files)
    {
        auto found = equal_range(it->cbegin(),it->cend(), book, compareIsbn);
        if(found.first != found.second)
        {
            ret.push_back(make_pair(index, found));
        }
    }
    return ret;
}

void reportResults(istream &in, ostream &os, const vector<vector<Sales_data>> &files)
{
    string str;
    
    while(in >> str)
    {
        auto trans = findBook(files, str);
        if(trans.empty())
        {
            cout << str << " not found in any stores." << endl;
            continue;
        }
        for(const auto &store: trans)
        {
            os << "store " << get<0>(store) << " sales: " 
                << accumulate(get<1>(store), get<2>(store),Sales_data(str))
                << endl;
        }
    }
}

void test_FindsBookWithISBN() 
{
    Sales_data s1("B008", 2, 100);
    Sales_data s2("A099", 4, 200);
    Sales_data s3("C900", 7, 300);

    vector<Sales_data> store1{ s1, s2 };
    vector<Sales_data> store2{ s3 };

    vector<vector<Sales_data>> files { store1, store2 };

    auto trans = findBook(files, "B008");
    cout << trans.size() << endl;
    // assert(trans.size() == 1);
    assert(get<0>(trans[0]) == 0);  // Store index
    assert(*get<1>(trans[0]) == s1);
}

void test_ReturnsErrorMessageIfNotFoundInStores()
{
    vector<Sales_data> store1{};
    vector<Sales_data> store2{};

    vector<vector<Sales_data>> files{ store1, store2 };

    stringstream input{"B123\n"};
    stringstream expected_output;
    reportResults(input, expected_output, files);

    assert(expected_output.str() == "B123 not found in any stores.\n");
}

void test_AccumulatesSalesDataCorrectly() 
{
    Sales_data s1("B008", 2, 100);
    Sales_data s2("B008", 1, 100);

    vector<Sales_data> store1{ s1, s2 };

    vector<vector<Sales_data>> files{ store1 };

    stringstream input{"B008\n"};
    stringstream expected_output;
    reportResults(input, expected_output, files);

    assert(expected_output.str() == "store 0 sales: isbn=B008 copies_sold=3 revenue=300\n");
}



int main(int argc, char **argv) 
{
    test_FindsBookWithISBN();
    test_ReturnsErrorMessageIfNotFoundInStores();
    test_AccumulatesSalesDataCorrectly();
    return 0;
}