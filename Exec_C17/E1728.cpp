#include "Headfile.h"

using namespace std;

int main() 
{
    default_random_engine engine;
    
    cout << engine.min() << " " << engine.max() << endl; 

    uniform_int_distribution<unsigned> uniform(0,9);

    for(size_t i  = 0; i < 10; ++i)
    {
        cout << uniform(engine) << " ";
    }
    cout << endl;


    return 0;
}
