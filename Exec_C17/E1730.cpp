#include "Headfile.h"

using namespace std;

void setSeed(unsigned int seed, int min, int max)
{
    default_random_engine engine;
    
    engine.seed(seed);

    cout << engine.min() << " " << engine.max() << endl; 

    uniform_int_distribution<unsigned> uniform(min, max);



    for(size_t i  = 0; i < 10; ++i)
    {
        cout << uniform(engine) << " ";
    }
    cout << endl;

}


int main() 
{
    setSeed(1, 1, 10);

    return 0;
}
