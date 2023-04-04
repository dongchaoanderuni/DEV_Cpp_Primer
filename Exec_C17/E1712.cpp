#include "Headfile.h"

using namespace std;

int main(int argc, char **argv) 
{
    bitset<10> ValueOfBits10;
    bitset<100> ValueofBits100;

    size_t pos = 0;
    bool   value = false;

    while(cin)
    {
        cin >> pos >> value;
        ValueofBits100.set(pos, value);
    }

    return 0;
}