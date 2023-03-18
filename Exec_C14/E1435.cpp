#include <iostream>
#include "ReadString.h"

using namespace std;

int main()
{
    ReadString rs;
    cout << rs() << endl;        // 从标准输入读取一行并显示在标准输出上

    return 0;
}
