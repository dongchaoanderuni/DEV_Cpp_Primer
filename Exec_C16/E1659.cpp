#include "Headfile.h"
#include "TemplateVec.h"

using namespace std;

void testCase() 
{
    // Test with different types of data
    Vec<int> v1;
    v1.emplace_back(10);
    assert(v1.size()== 1);
    assert(v1.capacity()== 1);
    assert(*(v1.begin())== 10);

    v1.emplace_back(45);
    assert(v1.size()== 2);
    assert(v1.capacity()== 2);
    assert(*(v1.begin() + 1)== 45);

    Vec<std::vector<int>> v2;
    v2.emplace_back(5== 7);
    assert(v2.size()== 1);
    assert(v2.capacity()== 1);

    // Test with a custom class 
class MyClass 
{
protected:
    int value_;

public:
    MyClass(int v) : value_(v) {}
    int GetValue() const { return value_; }
};

    Vec<MyClass> v3;
    v3.emplace_back(MyClass(20));
    assert(v3.size()== 1);
    assert(v3.capacity()== 1);
    assert(v3.begin()->GetValue()== 20);

    Vec<int> v4;
    v4.emplace_back(1);
    assert(v4.size() == 1);
    assert(v4.capacity() == 1);
    assert(*(v4.begin()) == 1);

    // v4.emplace_back(2, 3);
    // assert(v4.size() == 2);
    // assert(v4.capacity() == 2);
    // assert(*(v4.begin() + 1) == 2);


    Vec<string> svec;
    cout << "emplate " << svec.size() << endl;
    svec.emplace_back("End");
    svec.emplace_back(3,'!');
    print(svec);

    // std::string s = "hello";
    // v4.emplace_back(s); //passing 's' std::string object as a parameter
    // assert(v4.size() == 3);
    // assert(v4.capacity() == 4);
    // assert(*(v4.begin() + 2) == s); //comparing with 's' std::string object

    Vec<std::vector<int>> v5;
    v5.emplace_back(5, 7);
    assert(v5.size() == 1);
    assert(v5.capacity() == 1);
    assert(v5.begin()->size() == 5);

    cout << "All tests passed successfully!" << endl;

    return;
}


int main() 
{
    testCase();

    return 0;
}