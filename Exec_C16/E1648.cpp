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

int main() 
{
    string s("hi");
    /** input:string T string */
    cout << debug_rep(s) << endl;
    /** input:&s T string */
    cout << debug_rep(&s) << endl;
    /** 字符串常量 T */
    cout << debug_rep("hi") << endl;

    const string *sp = &s;
    /** input: pointer T string */
    cout << debug_rep(sp) << endl;
    /** input: &s T string */
    cout << debug_rep(&s) << endl;


    return 0;
}
