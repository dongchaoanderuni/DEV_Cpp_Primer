#include "Headfile.h"

using namespace std;

int main() 
{
   int x = 5;
   double y = 10.0;

//    std::cout << std::max(x, y) << std::endl; // prints 10

   std::cout << std::max<double>(x, y) << std::endl; // prints 10

    return 10;
}