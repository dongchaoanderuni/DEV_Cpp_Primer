#include "Headfile.h"

using namespace std;

template <typename T>
int compare(const T& lhs, const T& rhs)
{
    return (lhs < rhs) ? -1 : ((rhs < lhs) ? 1 : 0);
}

int main() 
{
    // Test case 1: comparing two integers
    int a = 10;
    int b = 20;
    assert(compare(a, b) == -1); // Expecting lhs is less than rhs 

    // Test case 2: comparing two floating point numbers
    float x = 3.5f; 
    float y = 1.7f;
    assert(compare(x, y) == 1); // Expecting rhs is less than lhs

    // Test case 3: comparing two character arrays
    char s1[] = "apple";
    char s2[] = "banana";
    assert(compare<string>(s1, s2) == -1); // Expecting s1 is less than s2

    // Test case 4: comparing two strings
    std::string t1 = "Hello there";
    std::string t2 = "Goodbye";
    assert(compare(t1, t2) == 1); // Expecting t2 is less than t1


    // Test case 5: comparing two strings
    assert(compare<string>("Hello there", "Goodbye") == 1); // Expecting t2 is less than t1

    std::cout << "All test cases passed!\n";
    return 0;
}
