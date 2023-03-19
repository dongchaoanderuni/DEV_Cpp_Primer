#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
#include "Variable.h"

using namespace std;

int main()
{
    VECTOR<STRING> text;
    STRING word;
    while(cin>>word)
    {
        for(auto it = word.begin();
        it != word.end(); it++)
        {
            *it = toupper(*it);
        }

        text.push_back(word);
    }

    for(auto it = text.begin();
        it != text.end()&& !it->empty(); it++)
    {   
        cout << *it << endl; 
    }

    return 0;

}