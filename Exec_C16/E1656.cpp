#include "Headfile.h"

using namespace std;

/** 打印任何我们不能处理的类型 */
template <typename T> string debug_rep(const T &t)
{
    ostringstream ret;
    ret << t;
    return ret.str();
}

/** 打印指针的之，后跟指针指向的对象 */
template <typename T> string debug_rep(T* p)
{
    ostringstream ret;
    ret << "pointer: " << p;
    if(p)
    {
        ret << " " << debug_rep(*p);
    }
    else 
    {
        ret << " null pointer.";
    }
    return ret.str();
}

string debug_rep(char* p)
{
    return debug_rep(string(p));
}

template <typename T>
ostream& print(ostream& os, const T& t)
{
    return os << t;
}

template <typename T, typename... Args>
ostream& print(ostream& os, const T& t, const Args&... rest)
{
    os << t << ", ";
    return print(os, rest...);
}

template <typename... Args>
ostream &errorMsg(ostream& os, const Args&... rest)
{
    return print(os,debug_rep(rest)...);
}

int main() 
{
    int x = 42;
    double y = 3.14;
    string s = "hello";

    errorMsg(cout, "x:", x, "y:", y, "s:", s); // expects: x:42, y:3.14, s:hello

    return 0;
}
