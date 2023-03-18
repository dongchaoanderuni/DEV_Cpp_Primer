#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using namespace placeholders;

bool divideByAll(vector<int> &vecInt, int targetValue)
{
    return (count_if(vecInt.begin(), vecInt.end(), bind(modulus<int>(), _1, targetValue)) == 0);
}

int main() {
    int arr[] {3, 982, 57, 45, 1129, 2048, 3077};
    constexpr size_t arr_size = sizeof(arr) / sizeof(*arr);
  
    // 转换成vector便于过滤
    vector<int> vecInt(arr, arr + arr_size);
    int targetValue = 3;

    if(!divideByAll(vecInt, targetValue))
    {
        cout << "Could not." << endl;
        return 0;
    }
    cout << "Yes." << endl;
    return 0;
}
