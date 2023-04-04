#include "Headfile.h"
#include <cmath>

using namespace std;

int main() 
{
    fstream inOut("copyOut.txt", fstream::ate | fstream::in | fstream::out);
    if(!inOut)
    {
        cerr << "Unable to open file." << endl;
        return EXIT_FAILURE;
    }

    auto endMark = inOut.tellg();
    inOut.seekg(0, fstream::beg);
    size_t count = 0;
    string line;

    while((inOut)
            &&(inOut.tellg() != endMark)
            &&(getline(inOut, line)))
    {
        cout << line << endl;
        count += line.size() + 1;
        auto mark = inOut.tellg();
        inOut.seekp(0, fstream::end);
        inOut << count;
        if(mark != endMark)
        {
            inOut << " "; 
        }
        inOut.seekg(mark);
    }

    inOut.seekp(0, fstream::end);
    inOut << "\n";

    return 0;
}
