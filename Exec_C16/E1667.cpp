#include "Headfile.h"

using namespace std;

/** 打印任何我们不能处理的类型 */
template <typename T> string debug_rep(const T &t)
{
    // cout <<"const T&" << endl;
    ostringstream ret;
    ret << t;
    return ret.str();
}

/** 打印指针的之，后跟指针指向的对象 */
template <typename T> string debug_rep(T* p)
{
    // cout << "T* " << endl; 
    ostringstream ret;
    ret << "pointer: " << p;
    if(p != nullptr)
    {
        ret << " "<<debug_rep(*p);
    }
    else 
    {
        ret << " null pointer.";
    }
    return ret.str();
}

string debug_rep(char* p)
{
    if (p == nullptr) 
    {
        return "null pointer";
    }
    return debug_rep(string(p));
}

template<>
string debug_rep(char* t)
{
    if (t == nullptr) 
    {
        return "null pointer";
    }
    return debug_rep(string(t));
}


template<>
string debug_rep(const char* t)
{
    if (t == nullptr)
    {
        return "null pointer";
    }
    return debug_rep(string(t));
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

    // // Testcase1: Testing debug_rep with integer value
    // int a = 10;
    // cout <<debug_rep(a) << endl;

    // // Testcase2: Testing debug_rep with double value
    // double b = 3.14;
    // cout <<debug_rep(b)<< endl;

    // // Testcase3: Testing debug_rep with string constant
    // cout <<debug_rep("Hello") << endl;

    // // Testcase4: Testing debug_rep with pointer pointing to an integer variable
    // int *ptr1 = &a;
    // cout <<debug_rep(ptr1)<< endl;

    // // Testcase5: Testing debug_rep with null pointer 
    // int *ptr2 = nullptr;
    // cout <<debug_rep(ptr2)<< endl;

    // // Testcase6: Testing debug_rep with pointer pointing to a double variable
    // double *ptr3 = &b;
    // cout << debug_rep(ptr3)<< endl;

    // // Testcase7: Testing debug_rep with pointer pointing to string object
    // std::string str("world");
    // std::string *ptr4 = &str;
    // cout << debug_rep(ptr4) << endl;

    // // Testcase8: Testing debug_rep with const char pointer
    // const char* cstr = "hello";
    // cout << debug_rep(cstr) << endl;

    // // Testcase9: Testing debug_rep with const char pointer (null)
    // char* ptr5 = nullptr;
    // cout << debug_rep(ptr5)<< endl;

    // // Testcase10:Testing debug rep with char pointer
    // char charArr[] = "book";
    // cout << debug_rep(charArr) << endl;

    // Test debug_rep with integer
    int x = 10;
    assert(debug_rep(x) == "10");

    // Test debug_rep with double
    double y = 3.14;
    assert(debug_rep(y) == "3.14");

    // Test debug_rep with string
    string strEins = "Hello, world!";
    assert(debug_rep(strEins) == "Hello, world!");

    // Test debug_rep with const char*
    const char* c_str = "C-style string";
    assert(debug_rep(c_str) == "C-style string");

    // Test debug_rep with char*
    char str[] = "Mutable string";
    char* ptr = str;
    assert(debug_rep(ptr) == "Mutable string");

    // Test debug_rep with null pointer
    char* null_ptr = nullptr;
    assert(debug_rep(null_ptr) == "null pointer");


    std::cout << "All test cases passed!\n";

    return 0;
}
