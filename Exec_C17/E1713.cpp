#include "Headfile.h"
#include<sstream> //Required for setting up input stream in tests
#include<cassert>

using namespace std;

void Grade(istream &in)
{
    bitset<10> ValueOfBits10;
    bitset<100> ValueofBits100;

    size_t  pos = 0;
    bool    value = false;

    while(in)
    {
        in >> pos >> value;
        ValueofBits100.set(pos, value);
    }

    cout << "Grade: " << ValueofBits100.count() << endl;
}


void test_Grade()
{
    std::istringstream input("1 1\n3 0\n4 1\n50 1\n"); // input to be read by function
    std::ostringstream output; // string stream to store output

    Grade(input); // call function on input stream
    output << "Grade: 3\n"; // expected output
    
    assert(input.eof()); // assert that we read all input
    assert(output.str() == "Grade: 3\n"); // assert that output matches expected
}

int main() {
    test_Grade();
    return 0;
}
