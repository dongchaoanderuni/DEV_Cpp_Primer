#include "Headfile.h"
#include <cmath>

using namespace std;

int main() 
{
    cout << hex << uppercase;
    cout    << "default format: " << 100 * sqrt(2.0) << '\n'
            << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
            << "fixed hex: " << fixed << 100 * sqrt(2.0) << '\n'
            << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
            << "use defaults: " << defaultfloat << 100 * sqrt(2.0) << '\n' 
        << endl;

    return 0;
}
