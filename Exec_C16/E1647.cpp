#include "Headfile.h"

using namespace std;

template <typename F, typename T1, typename T2>
auto flip(F f, T1&& t1, T2&& t2)->decltype(f(std::forward<T2>(t2),std::forward<T1>(t1)))
{
    return f(std::forward<T2>(t2),std::forward<T1>(t1));
}

void print_hello_world(std::string s1, std::string s2)
{
    std::cout << s1 << " " << s2 << std::endl;
}

int sum(int a, int b)
{
    return a + b;
}

bool starts_with_a(char a, char b)
{
    return (a == 'a');
}

int main() 
{
    // Test case 1: Testing with a simple function
    flip(print_hello_world, "World", "Hello");

    // Test case 2: Testing with a mathematical function
    assert(flip(sum, 5, 6) == 11);

    // Test case 3: Testing with a boolean function
    assert(flip(starts_with_a, 'a', 'b') == false);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
