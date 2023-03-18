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

string findLongestPartWithoutAsenderOrDesecnder(string &s, const string &ascender)
{
    string::size_type pos = 0;
    int length = 0;
    int targetlegnth = 0;
    string::size_type targetpos = 0;
    string targetStr;
    while((pos == s.find_first_of(ascender,pos))
        &&(pos != string::npos))
    {
        if((targetpos == s.find_first_of(ascender,pos+1))
            &&(targetpos != string::npos))
        {
            cout << __LINE__ << endl;
            targetlegnth = targetpos - pos;
            if(targetlegnth > length)
            {
                cout << targetlegnth << endl;
                cout <<s.substr(pos,targetlegnth) <<endl;
                targetStr.replace(0,s.substr(pos,targetlegnth).size(),s.substr(pos,targetlegnth));
            }
        }
        else
        {
            targetlegnth = s.size() - pos;
            if(targetlegnth > length)
            {
                cout << targetlegnth << endl;
                cout <<s.substr(pos,targetlegnth) <<endl;
                targetStr.replace(0,s.substr(pos,targetlegnth).size(),s.substr(pos,targetlegnth));
            }
            targetStr.replace(0,s.substr(pos,targetlegnth).size(),s.substr(pos,targetlegnth));
        }
        ++pos;
    }

    if((0 != targetlegnth)
        &&(targetlegnth < s.size()))
    {
        return targetStr;
    }
    return s;
}



int main(int argc, char* argv[])
{

    string s("abcdawvenanlzknvnanvzlkdzpezvkfnlfknnzgzvmbdiawvbc");
    string ascender("bdfghjklpqty");
    string targetStr;

    targetStr = findLongestPartWithoutAsenderOrDesecnder(s,ascender);

    cout << targetStr << endl;


    return 0;
}
