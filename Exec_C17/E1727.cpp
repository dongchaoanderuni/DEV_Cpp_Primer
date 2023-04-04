#include "Headfile.h"

using namespace std;


bool valid(const smatch& matches)
{
    if((matches[1].matched)
        &&(matches[2].matched))
    {
        return true;
    }
    return false;
}


string convert_zipcode(string &str) 
{
    string patternOfPhone = "(\\d{5})((-?)\\d{4})?";
    regex pattern(patternOfPhone);
    string fmt{"$1$2"};

    for(sregex_iterator iter(str.begin(), str.end(), pattern), endIter;
        (iter != endIter)&&(valid(*iter)); ++iter)
    {
        return  regex_replace(iter->str(), pattern , fmt);
    }

    return str;
}

int main() {

    // Testing valid input
    string input = "123456789";
    string expected_output = "123456789";

    string actual_output = convert_zipcode(input);

    if (expected_output == actual_output) {
        cout << "Test passed: converting " << input << " to " << actual_output << endl;
    } else {
        cout << "Test failed: converting " << input << " - expected output: "
            << expected_output << ", actual output: " << actual_output << endl;
    }

    // Testing invalid input
    input = "abcde12345";
    expected_output = "abcde12345"; // The input should not be modified

    actual_output = convert_zipcode(input);

    if (expected_output == actual_output) {
        cout << "Test passed: converting " << input << " to " << actual_output << endl;
    } else {
        cout << "Test failed: converting " << input << " - expected output: "
            << expected_output << ", actual output: " << actual_output << endl;
    }

    return 0;
}
