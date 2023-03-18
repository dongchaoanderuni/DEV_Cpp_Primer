#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

int main()
{
    string strEins{};
    string strZwei{};
    string response{};
    do
    {
        cin>>strEins>>strZwei;
        cout << "First: " << strEins << '\t' << "Second:" << strZwei << endl;
        if(strEins.size() < strZwei.size())
        {
            cout << "The short one is:\t" << strEins << endl;
        }
        else
        {
            cout << "The short one is:\t" << strZwei << endl;
        }
        cout << "Compare another two strings? Enter yes or no." << endl;
        cin >> response;

    }while((!response.empty())&&(response[0] != 'n'));

    return 0;
}