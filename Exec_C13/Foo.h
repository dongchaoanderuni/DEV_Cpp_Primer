#ifndef __FOO_H__
#define __FOO_H__

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const &;


private:
    /* data */
    vector<int> data;
};

Foo Foo::sorted() &&
{
    cout << "Right Value" << endl;
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const &
{
    cout << "Left Value" << endl;
    return Foo(*this).sorted();
}

#endif