#include "Headfile.h"
#include "TemplateSharedPtr.h"

using namespace std;

class MyClass {
public:
  string name;
  int age;

  MyClass(const string& n, int a) : name(n), age(a) {}

  void printInfo() const {
    cout << "Name: " << name << ", Age: " << age << endl;
  }
};

int main()
{
  // Test 1: Create tSharedPtr with new keyword and reset it
  tSharedPtr<int> p1(new int(42));
  cout << *p1 << endl;
  p1.reset();
  // cout << boolalpha << !p1 << endl;

  // Test 2: Create multiple shared_ptrs from the same object and modify it
  tSharedPtr<MyClass> p2(new MyClass("John", 25));
  tSharedPtr<MyClass> p3 = p2;
  p3->age = 30;
  p2->printInfo();
  p3->printInfo();

  // Test 3: Create tSharedPtr with custom deleter
  tSharedPtr<MyClass> p4(new MyClass("Jane", 22), [](MyClass* p){
    cout << "Deleting object" << endl;
    delete p;
    });
  p4.reset();

  // // Test 4: Create tSharedPtr with array and access elements
  // tSharedPtr<int[]> p5(new int[5]{1, 2, 3, 4, 5});
  // for (int i = 0; i < 5; ++i) 
  // {
  //   cout << p5[i] << " ";
  // }
  // cout << endl;

  // // Test 5: Create tSharedPtr to vector
  // tSharedPtr<vector<string>> p6(new vector<string>{"apple", "banana", "cherry"});
  // for (const auto& s : *p6) 
  // {
  //   cout << s << " ";
  // }
  // cout << endl;

    return 0;
}   