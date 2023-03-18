#include <iostream>
#include <vector>
#include <algorithm>    // for transform
#include <functional>   // for multiplies

using namespace std;

int main() {
    vector<int> v {1, 2, 3, 4, 5};
    
    // Multiply all elements of v by 2
    transform(v.begin(), v.end(), v.begin(), bind(multiplies<int>(),placeholders::_1,2));

    // Output the result
    for (const auto& elem : v) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
