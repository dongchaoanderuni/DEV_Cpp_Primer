#include "Print.h"
#include "StrBlob.h"
#include <cstring>
#include "HasPtr.h"


using namespace std;

#define LegalInput (2)

struct X
{
    X():ps(new string()),count(0) {cout << "X()" << endl;}
    X(const X& rhs): ps(rhs.ps), count(0) {cout << "X(const X&)" << endl;}
    X& operator =(const X& rhs) {string *tmpPs = new string(*rhs.ps);  delete ps; ps = tmpPs; count = rhs.count;  cout << "X& operator =(const X& rhs)" << *this->ps << " "<< this -> count<< endl;
    return *this; 
                                    }
    ~X() {cout << "~X()" << endl;}

    string *ps;
    int count;

};

void f_ref(X &x)
{
    return;
}

void f_notref(X x)
{
    return;
}


int main(int argc, char* argv[])
{
    cout << "局部变量" << endl;
    X a;
    cout << endl;

    cout << "非引用参数传递" << endl;
    f_notref(a);
    cout << endl;

    cout << "引用参数传递" << endl;
    f_ref(a);
    cout << endl;

    cout << "动态分配" << endl;
    X *pX = new X;
    cout << endl;

    cout  << "添加到容器中" << endl;
    vector<X> vecX;
    vecX.push_back(a);
    cout  << endl;

    cout << "释放动态分配对象" << endl;
    delete pX;
    cout << endl;

    cout << "间接初始化和赋值" << endl;
    X b = a;
    b = a;
    cout << endl;

    cout << "程序结束" << endl;

    return 0;
}
