#include <iostream>
#include <iostream>
#include <functional> // 使用 std::greater
#include <algorithm> // 使用 std::count_if
#include <vector>

using namespace std;

int main() 
{
    int arr[] {3, 982, 57, 45, 1129, 2048, 3077};
    constexpr size_t arr_size = sizeof(arr) / sizeof(*arr);
  
    // 转换成vector便于过滤
    std::vector<int> v(arr, arr + arr_size);

    const auto count = std::count_if(v.begin(), v.end(), bind(greater<int>(), placeholders::_1,1024));
  
    std::cout << "Count of values greater than 1024: " << count << '\n';

    return 0;
}