#include "Headfile.h"

using namespace std;

template<typename T>
int count_occurrences(std::vector<T> const& vec, T const& value) {
    int count = 0;
    for (auto const& elem: vec) 
    {
        if (elem == value)
        {
            ++count;
        }
    }
    return count;
}

template<>
int count_occurrences(std::vector<const char*> const &vec, const char* const &value)
{
    int count = 0;
    for (auto const& element: vec) 
    {
        if(std::strcmp(element, value) == 0) 
        {
            ++count;
        }
    }
    return count;
}

int main() {
    std::vector<double> double_vec {1.0, 2.2, 3.6, 4.8, 2.2};
    std::vector<int> int_vec {1, 2, 3, 4, 5, 2};
    std::vector<std::string> string_vec {"Hello", "World", "Hello"};

    double value1 = 2.2;
    int value2 = 2;
    std::string value3 = "Hello";

    std::cout << value1 << " appears " << count_occurrences(double_vec, value1) << " times in the double vector." <<std::endl;
    std::cout << value2 << " appears "<< count_occurrences(int_vec, value2) << " times in the int vector." <<std::endl;
    std::cout << value3 << " appears " << count_occurrences(string_vec, value3) << " times in the string vector." <<std::endl;

    std::vector<const char*> cvec {"foo", "bar", "baz", "foo"};
    const char* cvalue = "foo";
    int ccount = count_occurrences(cvec, cvalue);
    std::cout << "Found " << ccount << " occurrences of " << cvalue << std::endl;

    return 0;
}