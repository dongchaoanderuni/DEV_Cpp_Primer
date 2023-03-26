#include "Headfile.h"

using namespace std;

template<typename T1, typename T2>
auto sum(T1 a, T2 b)->decltype(a+b)
{
    return a+b;
}

int main() 
{
    // Test case 1: adding two integers
    int a = 10;
    int b = 20;
    assert(sum(a, b) == 30);

    // Test case 2: adding a float and an integer
    float x = 3.5f; 
    int y = 2;
    assert((sum(x, y) - 5.5f) <= 0.00001f);

    // Test case 3: adding two long long integers
    long long d = 1234567898765LL;
    long long e = 9876543212345LL;
    assert(sum(d, e) == 11111111111110LL);

    // Test case 4: concatenate two strings
    std::string str1 = "Hello";
    std::string str2 = " world!";
    std::string result = sum(str1, str2);
    assert(result == "Hello world!");
    
    std::cout << "All test cases passed!\n";
    return 0;
}
