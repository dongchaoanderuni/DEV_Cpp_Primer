#include "Print.h"
#include <cstring>
#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "PtrStrBlobPtr.h"

using namespace std;

int main()
{
    StrBlob b{"hello", "world"};        // 定义 StrBlob 对象 b
    StrBlobPtr p1(b);                   // 获取 b 的 StrBlobPtr
    PtrStrBlobPtr h(&p1);   

    cout << h->deref() << endl;
    
    return 0;
}