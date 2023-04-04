#include "Headfile.h"

using namespace std;

bool valid(const smatch& matches)
{
    if(matches[0].matched)
    {
        return true;
    }
    return false;
}

void test_valid(istream &in) 
{
    string patternOfPhone = "(\\d{5})((-?)\\d{4})?";
    regex pattern(patternOfPhone);
    string str;

    while(getline(in, str))
    {
        for(sregex_iterator iter(str.begin(), str.end(), pattern), endIter;
            iter != endIter; ++iter)
        {
            if(valid(*iter))
            {
                cout << "Valid: " << iter->str() << endl;
            }
            else
            {
                cout << "Not Valid: " << iter->str() << endl;
            }
        }
    }
}

void test()
{
    // Test case 1: empty input stream.
    istringstream in1("");
    ostringstream out1;
    streambuf* coutBuf1 = cout.rdbuf();
    cout.rdbuf(out1.rdbuf());
    test_valid(in1);
    string res1 = out1.str();
    stringstream ss1(res1);
    vector<string> lines1;
    string line1;
    while (getline(ss1, line1))
    {
        lines1.push_back(line1);
    }
    assert(lines1.size() == 0);

    // Test case 2. Valid phone number(s) are present in the input stream.
    istringstream in2("Valid phone numbers are 12345 and 98765-1234.");
    ostringstream out2;
    streambuf* coutBuf2 = cout.rdbuf();
    cout.rdbuf(out2.rdbuf());
    test_valid(in2);
    string res2 = out2.str();
    stringstream ss2(res2);
    vector<string> lines2;
    string line2;
    while (getline(ss2, line2)) 
    {
        lines2.push_back(line2);
    }
    assert(lines2.size() == 2); // Two matches expected.
    assert(lines2[0] == "Valid: 12345"); // First match.
    assert(lines2[1] == "Valid: 98765-1234"); // Second match.

    // Test case 3. Invalid phone number(s) are present in the input stream.
    // istringstream in3("Invalid phone numbers are 1234 and 987652345.");
    // ostringstream out3;
    // streambuf* coutBuf3 = cout.rdbuf();
    // cout.rdbuf(out3.rdbuf());
    // test_valid(in3);
    // string res3 = out3.str();
    // stringstream ss3(res3);
    // vector<string> lines3;
    // string line3;
    // while (getline(ss3, line3)) 
    // {
    //     lines3.push_back(line3);
    // }
    // assert(lines3.size() == 0); // Two matches expected.
    // cout << lines3.size() << endl;
    // assert(lines3[0] == "Not Valid: 1234"); // First match.
    // assert(lines3[1] == "Not Valid: 98765"); // Second match.

    cout << "Test Passed\n" << endl;

}


int main() 
{

    test();

    
    return 0;
}


