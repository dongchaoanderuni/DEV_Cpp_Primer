#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>
// #include "Sales_data.h"

using namespace std;

istream& readfileandresetistream(istream & is)
{
    string str;
    auto old_state = cin.rdstate();

    while(is >> str)
    {
       cout << str << endl; 
    }

    // is.clear((is.rdstate())&~cin.badbit&~cin.eofbit&~cin.failbit);
    is.setstate(old_state);

    return is;
}

void readfileandstoreinvector(string& ifile, vector<string>& vecStr)
{
    string line;
    ifstream in(ifile);

    if(in)
    {
        while(getline(in, line))
        {
            vecStr.push_back(line);
        }

        in.close();
    }
    else
    {
        cerr << "-1" << endl;
    }


    return;
}

struct PersonInfo
{
    string name;
    vector<string> phones;
    /* data */
};

#define LegalInput (2)

int main(int argc, char* argv[])
{

    string str;
    vector<string> vecStr;

    if(LegalInput != argc)
    {
        cerr << "illegal input params:" << argc << endl;
        return -1;
    }


    str = argv[1];

    // cout << __LINE__ << endl;
    readfileandstoreinvector(str,vecStr);
    // cout << __LINE__ << endl;

    for(auto ele:vecStr)
    {
        // cout << __LINE__ << endl;
        cout << ele  << endl;
        // cout << __LINE__ << endl;

    }



    // int val;
    // string str;
    // vector<string> vecStr;
    // string line, word;
    // vector<PersonInfo> people;

    // while(getline(cin, line))
    // {
    //     PersonInfo info;

    // }

    return 0;
}
