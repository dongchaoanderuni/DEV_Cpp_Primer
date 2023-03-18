#include "Print.h"
#include <cstring>
#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;

#define LegalInput (2)

int main(int argc, char **argv)
{
    // open the file from which user will query words
    ifstream infile;
	// open returns void, so we use the comma operator XREF(commaOp) 
	// to check the state of infile after the open
    if (argc < 2 || !(infile.open(argv[1]), infile)) {
        cerr << "No input file!" << endl;
        return EXIT_FAILURE;
    }
	runQueries(infile);
    return 0;
}
