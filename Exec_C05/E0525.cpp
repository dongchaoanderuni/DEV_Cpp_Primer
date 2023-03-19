#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

int main()
{
    int intEins{0};
    int intZwei{0};

    

    while(cin >> intEins >> intZwei)
    {


        try
        {
            if(0 == intZwei)
            {
                throw runtime_error("It could not equal to 0.");
            }
            cout << intEins/intZwei << endl; 
        }
        catch(runtime_error err)
        {
            std::cerr << err.what() << "\nTry another int not equal 0."<< '\n';
        }
        

    }

    return 0;
}