#include "Print.h"

using namespace std;

#define LegalInput (2)

void readFileAndStoreInMap(istream &os, multimap<string, string> &authorsBooks)
{
    string author;
    string book;

    while(os>>author)
    {
        os >> book;
        authorsBooks.insert(make_pair(author,book));
    }
    return;
}

void eraseAuthorAndBooks(const string &str, multimap<string, string> &authorsBooks)
{   
    auto pos = authorsBooks.equal_range(str);
    if(pos.first != pos.second)
    {
        authorsBooks.erase(pos.first, pos.second);
    }
    return;
}

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

    // istream_iterator<string> inAuthors(inAuthorFile), eofAuthors;
    // istream_iterator<string> inBooks(inBookFile), eofBooks;
    multimap<string, string> authorsBooks;

    readFileAndStoreInMap(inFile,authorsBooks);
    print(cout, authorsBooks);

    eraseAuthorAndBooks("the", authorsBooks);
    print(cout, authorsBooks);


}
