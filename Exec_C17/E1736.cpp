#include "Headfile.h"
#include <cmath>

using namespace std;

int main() 
{
    cout<< hex << uppercase
            << setw(20) << "default format: " << 100 * sqrt(2.0) << '\n'
            << setw(20) << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
            << setw(20) << "fixed hex: " << fixed << 100 * sqrt(2.0) << '\n'
            << setw(20) << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
            << setw(20) << "use defaults: " << defaultfloat << 100 * sqrt(2.0) << '\n' 
        << endl;

    return 0;
}
