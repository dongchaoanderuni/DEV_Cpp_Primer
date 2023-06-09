#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht*wd, ' ') {}
    Screen(pos ht, pos wd, char c): height(ht), width(wd),contents(ht*wd, c) {}
    char get() const {return contents[cursor];}
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    void some_member() const {++access_ctr;}

private:
    mutable size_t access_ctr;
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

};

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const 
{
    pos row = r * width;
    return contents[row + c];
}

class Window_Mgr
{
private:
    std::vector<Screen> screens{Screen(24,80,'c')};    
};


int main()
{
    return 0;
}
