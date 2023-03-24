#include "Headfile.h"
#include "TemplateBeginEnd.h"

using namespace std;

int main() 
{
    int arr[5] = { 4, 2, 8, 5, 1 };
    
    auto rtValueEins = tempFindBeginAndEnd(arr);

    cout << *rtValueEins.first << endl;


    int arrInt[] = {1, 2, 3};
    auto rtValueZwei = tempFindBeginAndEnd(arrInt);
    cout << *rtValueZwei.first << endl;

    float arrFloat[] = {1.5f, 2.3f, 3.7f};
    auto rtValueDrei = tempFindBeginAndEnd(arrFloat);
    cout << *rtValueDrei.first << endl;

    string arrStr[] = {"abc", "def", "ghi"};
    auto rtValueVier = tempFindBeginAndEnd(arrStr);
    cout << *rtValueVier.first << endl;

    /* zero-length arrays are not permitted in C++ */
    // int arrEmpty[0];
    // auto rtValueFunf = tempFindBeginAndEnd(arrEmpty);
    // cout << *rtValueFunf.first << endl;

    bool arrBool[] = {true, false, true};
    auto rtValueSechs = tempFindBeginAndEnd(arrBool);
    cout << *rtValueSechs.first << endl;

    char arrChar[] = {'a', 'b', 'c'};
    auto rtValueSieben = tempFindBeginAndEnd(arrChar);
    cout << *rtValueSieben.first << endl;

    /* deduced conflicting types ('int' vs 'char') for initializer list element type */
    // auto arrMixed = {1, 'a', 2, 'b', 3, 'c'};
    // auto rtValueAcht = tempFindBeginAndEnd(arrMixed);
    // cout << *rtValueAcht.first << endl;


    int arrNegative[] = {-3, -5, -1};
    auto rtValueNeun = tempFindBeginAndEnd(arrNegative);
    cout << *rtValueNeun.first << endl;

    int arrOne[1] = {5};
    auto rtValueZehn = tempFindBeginAndEnd(arrOne);
    cout << *rtValueZehn.first << endl;

    int arrLarge[1000];
    auto rtValueElf = tempFindBeginAndEnd(arrLarge);
    cout << *rtValueElf.first << endl;


    return 0;
}