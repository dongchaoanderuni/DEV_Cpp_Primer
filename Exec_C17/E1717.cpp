#include "Headfile.h"

using namespace std;

int main() 
{
    string text ="receipt freind theif receive ";

    regex patternEins("[[:alpha:]]*[^c]ei[[:alpha:]]*", regex::icase);

    for(sregex_iterator iter(text.cbegin(),text.cend(), patternEins), endIter; iter != endIter; ++iter)
    {
        smatch match = *iter;
        cout << match.str() << endl;
    }
    
    return 0;
}