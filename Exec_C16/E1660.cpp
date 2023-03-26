#include "Headfile.h"
#include "TemplateSharedPtr.h"

using namespace std;

class MyClass 
{
public:
    int a;
    string b;

    MyClass(int num, string str)
        : a(num), b(str) { }
};

int main() 
{
    auto ptr1 = make_tShared<int>(42);
    // assert(ptr1 != nullptr);
    assert(*ptr1 == 42);

    auto ptr2 = make_tShared<MyClass>(13, "Hello");
    // assert(ptr2 != nullptr);
    assert(ptr2->a == 13);
    assert(ptr2->b == "Hello");

    auto ptr3 = make_tShared<string>("Test");
    // assert(ptr3 != nullptr);
    assert(*ptr3 == "Test");


    std::cout << "All test cases passed!\n";
    return 0;
}
