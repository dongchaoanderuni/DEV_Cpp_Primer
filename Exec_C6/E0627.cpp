#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;


int sumofinputs(initializer_list<int> inputList)
{
    int sum{0};

    for(auto ele:inputList)
    {
        sum+= ele;
    }

    return sum;
}

int main()
{
    int sum{0};

    cout << "sum:\t" << sum << endl;
    cout << "sum:\t" << sumofinputs({0,1,3,4,56,85,7}) <<endl;
    cout << "sum:\t" << sumofinputs({0,14,12,52,3,6,36,3,6,3,6,34,3,5,3,3,54,57}) << endl;

    return 0;

}
