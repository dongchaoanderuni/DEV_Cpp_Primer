#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> words = {"pooh", "pooh", "hello", "world"};
    auto iter = find_if(words.begin(), words.end(), bind(not_equal_to<string>(), placeholders::_1, "pooh"));
    if (iter != words.end()) {
        cout << "The first string that is not equal to 'pooh' in the vector is: " << *iter << endl;
    } else {
        cout << "There is no string that is not equal to 'pooh' in the vector." << endl;
    }
    return 0;
}
