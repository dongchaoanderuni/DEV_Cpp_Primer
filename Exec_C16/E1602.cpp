#include "Headfile.h"
#include "TemplateCompare.h"

using namespace std;

int main() 
{
    int result = compare(5, 3);
    switch(result)
    {
    case 1:
        cout << "Test Passed\n";
        break;
    default:
        cout << "Test Failed\n";
        break;
    }

    result = compare(3, 5);
    switch(result)
    {
    case -1:
        cout << "Test Passed\n";
        break;
    default:
        cout << "Test Failed\n";
        break;
    }

    result = compare(4, 4);
    switch(result)
    {
    case 0:
        cout << "Test Passed\n";
        break;
    default:
        cout << "Test Failed\n";
        break;
    }

    result = compare(5.5, 3.3);
    switch(result)
    {
    case 1:
        cout << "Test Passed\n";
        break;
    default:
        cout << "Test Failed\n";
        break;
    }

    result = compare(5.5, 3.3);
    switch(result)
    {
    case 1:
        cout << "Test Passed\n";
        break;
    default:
        cout << "Test Failed\n";
        break;
    }

    result = compare(3.1, 5.9);
    switch(result)
    {
    case -1:
        cout << "Test Passed\n";
        break;
    default:
        cout << "Test Failed\n";
        break;
    }

    result = compare(4.0, 4.0);
    switch(result)
    {
    case 0:
        cout << "Test Passed\n";
        break;
    default:
        cout << "Test Failed\n";
        break;
    }

    result = compare('a', 'A');
    switch(result)
    {
    case 1:
        cout << "Test Passed\n";
        break;
    default:
        cout << "Test Failed\n";
        break;
    }

    result = compare('Z', 'z');
    switch(result)
    {
    case -1:
        cout << "Test Passed\n";
        break;
    default:
        cout << "Test Failed\n";
        break;
    } 

    result = compare('@', '@');
    switch(result)
    {
    case 0:
        cout << "Test Passed\n";
        break;
    default:
        cout << "Test Failed\n";
        break;
    }

    // result = compare("Hello", "Hi");
    // switch(result)
    // {
    // case 1:
    //     cout << "Test Passed\n";
    //     break;
    // default:
    //     cout << "Test Failed\n";
    //     break;
    // }

    return 0;
}
