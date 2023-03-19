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

void findAllofNumbersAndAlphabets(string &s, const string &numbers, const string &alphabets)
{
    string::size_type pos = 0;
    while((pos = s.find_first_of(numbers,pos))!=string::npos)
    {
        cout << "found nubmer at index: " << pos << " element is " << s[pos] << endl;
        ++pos;
    }

    pos = 0;
    while((pos = s.find_first_of(alphabets,pos))!=string::npos)
    {
        cout << "found alphabets at index: " << pos << " element is " << s[pos] << endl;
        ++pos;
    }
}

void findAllofNumbersAndAlphabetsZwei(string &s, const string &numbers, const string &alphabets)
{
    string::size_type pos = 0;
    while((pos = s.find_first_not_of(numbers,pos))!=string::npos)
    {
        cout << "found alphabet at index: " << pos << " element is " << s[pos] << endl;
        ++pos;
    }

    pos = 0;
    while((pos = s.find_first_not_of(alphabets,pos))!=string::npos)
    {
        cout << "found numbers at index: " << pos << " element is " << s[pos] << endl;
        ++pos;
    }
}

int main(int argc, char* argv[])
{

    string s("ab2c3d7R4E6");
    string numbers("0123456789");
    string alphabets("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

    findAllofNumbersAndAlphabets(s,numbers, alphabets);

    cout << __LINE__<< endl;

    findAllofNumbersAndAlphabetsZwei(s,numbers, alphabets);

    return 0;
}
