#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    cout << argc << endl;
    for(int index = 0; index < argc; ++index)
    {
        cout << argv[index]<<'\t';
    }
    cout << endl;


    return 0;

}
