#include <algorithm>
#include <iostream>
#include <vector>
#include "TestEqInstance.h"

using namespace std;

int main() {
    std::vector<int> nums = { 1, 5, 3, 7, 3, 9, 0, 3 };
    int oldValue = 3, newValue = 99;

    // 使用 Equal 对象查找需要替换的元素
    auto eq = TestEqInstance(oldValue);
    std::replace_if(nums.begin(), nums.end(), eq, newValue);
    /*
    template< class ForwardIt, class UnaryPredicate, class T >
    constexpr void replace_if( ForwardIt first, ForwardIt last, UnaryPredicate p, const T& new_value );
    first、last：要替换元素的范围。
    p：替换元素的条件，即一元谓词。
    new_value：新值，将满足条件的元素替换为该值。

    它的作用是遍历[first, last)范围内的所有元素，对每个元素 e，如果 p(e) == true，则用new_value替换e.
    返回值为void，表示替换操作没有失败的情况。
    */

    // 输出修改后的结果
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}