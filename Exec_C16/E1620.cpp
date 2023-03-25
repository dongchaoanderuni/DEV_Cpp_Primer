#include "Headfile.h"
#include "TemplateVec.h"

using namespace std;

int main()
{
    // default constructor
    Vec<int> vec;
    print(vec);

    assert(vec.size() == 0);
    assert(vec.capacity() == 0);

    print(vec);

    // initializer list constructor
    Vec<int> vec2{1, 2, 3};
    print(vec2);

    assert(vec2.size() == 3);
    assert(vec2.capacity() >= 3);
    assert(vec2[0] == 1);
    assert(vec2[1] == 2);
    assert(vec2[2] == 3);

    print(vec2);

    // // copy constructor and assignment operator
    Vec<int> vec3(vec2);
    print(vec3);
    assert(vec3.size() == vec2.size());
    assert(vec3.capacity() == vec2.capacity());
    assert(vec3[0] == vec2[0]);
    assert(vec3[1] == vec2[1]);
    assert(vec3[2] == vec2[2]);
    print(vec3);

    vec = vec3;
    print(vec);
    assert(vec.size() == vec3.size());
    assert(vec.capacity() == vec3.capacity());
    assert(vec[0] == vec3[0]);
    assert(vec[1] == vec3[1]);
    assert(vec[2] == vec3[2]);
    print(vec);

    // // move constructor and move assignment operator
    Vec<int> vec4(std::move(vec3));
    print(vec4);
    assert(vec4.size() == 3);
    assert(vec4.capacity() >= 3);
    assert(vec3.size() == 0); // vec3 has been moved from
    print(vec4);

    Vec<int> vec8(vec2);
    print(vec8);
    vec3 = std::move(vec8);
    assert(vec3.size() == 3);
    assert(vec3.capacity() >= 3);
    assert(vec8.size() == 0); // vec2 has been moved from
    print(vec8);

    // // access elements
    vec4[0] = 4;
    print(vec4);
 
    assert(vec4[0] == 4);

    // // push_back and reserve
    vec4.reserve(10);
    print(vec4);
    assert(vec4.size() == 3);
    assert(vec4.capacity() >= 10);

    vec4.push_back(5);
    print(vec4);
    assert(vec4.size() == 4);
    assert(vec4[3] == 5);

    // // comparison operators
    Vec<int> vec5 = {1, 2, 3};
    Vec<int> vec6 = {1, 2, 3, 4};
    Vec<int> vec7 = {1, 2, 4};

    assert(vec5 == vec2);
    assert(vec5 != vec6);
    assert(vec5 < vec6);
    assert(vec6 > vec5);
    assert(vec5 <= vec7);
    assert(vec6 >= vec5);
    assert(vec5 <= vec7);
    assert(vec5 < vec7);
    assert(vec7 > vec5);

    const Vec<int> vec10(vec4);
    print(vec10);

    std::cout << "All test cases passed!" << std::endl;

    return 0;
}