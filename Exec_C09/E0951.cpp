#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
// #include "Sales_data.h"
#include "Variable.h"

using namespace std;

class ClassDate
{
public:
    ClassDate() = default;
    ClassDate(const string &s);
    void showDate() {cout << Jahr << " " << Monate << " " << Tag << endl;}

private:
    unsigned int Jahr;
    unsigned int Monate;
    unsigned int Tag;
    vector<string> Monates = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    vector<string> SubMonates = {"Jan", "Feb", "Mar", "Apr","May", "Jun", "Jul","Aug", "Sept","Oct","Nov","Dec"};

};

ClassDate::ClassDate(const string &s)
{
    string::size_type pos = 0;
    Jahr = 0;
    Monate = 0;
    Tag = 0;
    string::size_type begin = 0;
    string::size_type end   = 0;

    // cout << s << endl;
    Jahr = stoi(s.substr(s.size()-4,4));

    for(auto index = 0; index < Monates.size(); ++index)
    {
        if((pos = s.find(Monates[index]))!= string::npos)
        {            
            Monate = index+1;
        }
    }

    if((begin = s.find_first_of(",/ "))!= string::npos)
    {
        if((!Monate)&&(pos = s.substr(0,begin).find_first_of("123456789")!= string::npos))
        {
            Monate = stoi(s.substr(0,begin));
        }
        else if(begin <= 4)
        {
            for(auto index = 0; index < Monates.size(); ++index)
            {
                if((pos = s.find(SubMonates[index])!= string::npos))
                {
                    Monate = index+1;
                }
            }
        }
        else
        {
            for(auto index = 0; index < Monates.size(); ++index)
            {
                if((pos = s.find(Monates[index]))!= string::npos)
                {            
                    Monate = index+1;
                }
            }
        }
        if((end = s.find_first_of(",/ ", begin+1))!= string::npos)
        {
            Tag = stoi(s.substr(begin+1, end-begin));
        }
    }

}

int main(int argc, char* argv[])
{
    string input;

    if(2 != argc)
    {
        cout << __LINE__ << " input params not legal " << argc << endl;
        return -1;
    }

    ifstream in(argv[1]);

    while(getline(in, input))
    {
        ClassDate DateEins(input);
        DateEins.showDate();
    }

    return 0;
}
