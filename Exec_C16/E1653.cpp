#include "Headfile.h"

using namespace std;

template <typename T>
ostream& print(ostream& os, const T& t)
{
    return os << t;
}

template <typename T, typename... Args>
ostream& print(ostream& os, const T& t, const Args&... rest)
{
    os << t << ", ";
    return print(os, rest...);
}

int main() 
{
    // Set up output stream
    stringstream ss;

    // Test case 1: Print one integer value
    int a = 10;
    print(ss, a);
    cout << ss.str() << endl; // Expecting "10"

    ss.str("");
    ss.clear();

    // Test case 2: Print multiple values
    string s = "Hello";
    float b = 3.14f;
    char c = '!';
    bool e = true;
    print(ss, s, a, b, c,e); // Expecting "Hello, 10, 3.14, !"
    cout << ss.str() << endl;

    // Clear and reuse the output stream
    ss.str("");
    ss.clear();

    // Test case 3: Print one character
    char d = '$';
    print(ss, d); // Expecting "$"
    cout << ss.str() << endl;

    return 0;
}
