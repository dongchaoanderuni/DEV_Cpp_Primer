#include "Headfile.h"

using namespace std;

int main(int argc, char **argv) 
{
    bitset<32> bitvec(1U);

    bool isSet = bitvec.any();
    cout << "isSet: " << isSet << endl;

    bool isNotSet = bitvec.none();
    cout << "isNotSet: " << isNotSet << endl;

    bool allSet = bitvec.all();
    cout << "allSet: " << allSet << endl;

    size_t countBits = bitvec.count();
    cout << "countBits: " << countBits << endl;

    size_t sz = bitvec.size();
    cout << "sz: " << sz << endl;

    cout << "flip(): " << bitvec.flip() << endl;

    cout << "flip(pos): " << bitvec.flip(0) << endl;

    cout << "reset(): " << bitvec.reset() << endl;

    cout << "set(): " << bitvec.set() << endl;

    cout << "set(pos,value): " << bitvec.set(0, 0) << endl; 


    bitset<32> bitvecEins("10000000100001100101110");
    bitset<32> bitvecZwei;
    cout << bitvecEins << endl;
    cout << bitvecZwei << endl;

    return 0;
}