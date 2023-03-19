#include <iostream>
#include <fstream>
#include <sstream>
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

int main()
{

    int val;
    vector<string> vecStr;
    vector<PersonInfo> people;
    string line,phone;
    istringstream record;

    while(getline(cin, line))
    {
        PersonInfo info;
        
        record.clear();
        record.str(line);
        record >> info.name;

        while(record >> phone)
        {
            info.phones.push_back(phone);
        }

        people.push_back(info);
    }


    return 0;
}
