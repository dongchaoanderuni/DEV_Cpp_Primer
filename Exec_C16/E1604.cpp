#include "Headfile.h"
#include "TemplateFind.h"

using namespace std;

int main() 
{
    vector<int> vec{ 4, 2, 8, 5, 1 };
 
    // Find the first occurence of 5 in the vector
    auto location = tempFind(vec.begin(), vec.end(), 5);
    print(location,vec.end());

    list<string> myList{"apple", "banana", "orange"};
    
    // Test: find an existing element
    auto result1 = tempFind(myList.begin(), myList.end(), "banana");
    print(result1, myList.end());

    // Test: find a non-existing element
    auto result2 = find(myList.begin(), myList.end(), "grape");
    print(result2, myList.end());

    return 0;
}
