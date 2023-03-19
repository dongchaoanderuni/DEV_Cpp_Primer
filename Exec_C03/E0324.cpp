#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"

using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10,42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    int i = 0;
    const int init = 0;

    AUTO begin  =   v1.begin();
    AUTO end    =   v1.end();

    if(begin != end)
    {
        while(begin!=end)
        {
            COUT << i << ":" << *begin;
            i++;
            ++begin;
        }
        COUT << endl;
    }
    else
    {
        COUT << "v1 is empty." << ENDL;
    }

    cout << "v2:  ";

    begin  =   v2.begin();
    end    =   v2.end();
    i = init;

    if(begin != end)
    {
        while(begin!=end)
        {
            COUT << i << ":" << *begin << '\t';
            i++;
            ++begin;
        }
        COUT << endl;
    }
    else
    {
        COUT << "v2 is empty." << ENDL;
    }

    cout << "v3:  ";
    
    begin  =   v3.begin();
    end    =   v3.end();
    i = init;

    if(begin != end)
    {
        while(begin!=end)
        {
            COUT << i << ":" << *begin << '\t';
            i++;
            ++begin;
        }
        COUT << endl;
    }
    else
    {
        COUT << "v3 is empty." << ENDL;
    }

    cout << "v4:  ";
    
    begin  =   v4.begin();
    end    =   v4.end();
    i = init;

    if(begin != end)
    {
        while(begin!=end)
        {
            COUT << i << ":" << *begin << '\t';
            i++;
            ++begin;
        }
        COUT << endl;
    }
    else
    {
        COUT << "v4 is empty." << ENDL;
    }


    cout << "v5:  ";
    
    begin  =   v5.begin();
    end    =   v5.end();
    i = init;

    if(begin != end)
    {
        while(begin!=end)
        {
            COUT << i << ":" << *begin << '\t';
            i++;
            ++begin;
        }
        COUT << endl;
    }
    else
    {
        COUT << "v5 is empty." << ENDL;
    }

    cout << "v6:  ";
    
    AUTO Strbegin  =   v6.begin();
    AUTO Strend    =   v6.end();
    i = init;

    if(Strbegin != Strend)
    {
        while(Strbegin!=Strend)
        {
            COUT << i << ":" << *Strbegin << '\t';
            i++;
            ++Strbegin;
        }
        COUT << endl;
    }
    else
    {
        COUT << "v6 is empty." << ENDL;
    }


    cout << "v7:  ";
    
    Strbegin  =   v7.begin();
    Strend    =   v7.end();
    i = init;

    if(Strbegin != Strend)
    {
        while(Strbegin!=Strend)
        {

            COUT << i << ":" << *Strbegin << '\t';
            i++;
            ++Strbegin;
        }
        COUT << endl;
    }
    else
    {
        COUT << "v7 is empty." << ENDL;
    }

    return 0;

}