#include "Headfile.h"

using namespace std;

int main() 
{
    string text ="receipt freind theif receive ";

    regex patternEins("[[:alpha:]]*[^c]ei[[:alpha:]]*", regex::icase);

    smatch matches;

    if(regex_search(text, matches, patternEins))
    {
        for(auto ele:matches)
        {
            cout << "Found match: " << ele << endl;
        }
    }
    else
    {
        cout << "Not found." << endl;
    }

    return 0;
}
