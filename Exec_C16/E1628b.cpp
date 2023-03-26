#include "Headfile.h"
#include "TemplateUniquePtr.h"

using namespace std;

class MyClass {
public:
    MyClass() { std::cout << "MyClass created" << std::endl; }
    ~MyClass() { std::cout << "MyClass destroyed" << std::endl; }

    void someMethod() {
        std::cout << "Hello World" << std::endl;
    }
};

void foo(tUniquePtr<MyClass> ptr) {
    ptr->someMethod();
}

void foo(unique_ptr<MyClass> ptr) {
    ptr->someMethod();
}

void TestExperiment()
{
    // Test 1: Creating a new instance of unique_ptr
    tUniquePtr<MyClass> ptr = tUniquePtr<MyClass>(new MyClass{});
    ptr->someMethod();

    // Test 2: Moving ownership of the pointer between two instances
    tUniquePtr<MyClass> ptr1 = tUniquePtr<MyClass>(new MyClass{});
    tUniquePtr<MyClass> ptr2 = std::move(ptr1);
    ptr2->someMethod();

    // Test 3: Resetting the pointer
    tUniquePtr<MyClass> ptr3 = tUniquePtr<MyClass>(new MyClass{});
    ptr3.reset(new MyClass{});
    


    // Test 4: Releasing the pointer from an instance and leaving it to caller
    tUniquePtr<MyClass> ptr4 = tUniquePtr<MyClass>(new MyClass{});
    foo(std::move(ptr4));
}

void ControlGroup()
{
    auto ptrUptr = unique_ptr<MyClass>(new MyClass{});
    ptrUptr->someMethod();

    auto ptr1Uptr = unique_ptr<MyClass>(new MyClass{});
    auto ptr2Uptr = std::move(ptr1Uptr);
    ptr2Uptr->someMethod();

    auto ptr3Uptr = unique_ptr<MyClass>(new MyClass{});
    ptr3Uptr.reset(new MyClass{});

    auto ptr4Uptr = unique_ptr<MyClass>(new MyClass{});
    foo(std::move(ptr4Uptr));
}

int main() 
{
    TestExperiment();

    // ControlGroup();

}