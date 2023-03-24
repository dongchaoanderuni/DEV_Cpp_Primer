#include "Headfile.h"
#include "TemplatePrint.h"

using namespace std;

int main() 
{
    int arr[5] = { 4, 2, 8, 5, 1 };
    print(arr);

    int arrEins[] = {1, 2, 3, 4, 5};
    print(arrEins);

    char arrZwei[] = {'a', 'b', 'c', 'd'};
    print(arrZwei);

    double arrDrei[] = {1.23, 4.56, 7.89};
    print(arrDrei);

    bool arrVier[] = {true, false, true, false};
    print(arrVier);

    /* zero-length arrays are not permitted in C++*/
    // int arrFunf[] = {};
    // print(arrFunf);

    int arrSechs[] = {42};
    print(arrSechs);

    int arrSieben[100];
    for(int i = 0; i < 100; i++)
    {
        arrSieben[i] = i;
    }
    print(arrSieben);

    string arrNeun[] = {"hello", "world"};
    print(arrNeun); 

    int arrZehn[][2] = {{1, 2}, {3, 4}, {5, 6}};
    print(arrZehn);

    return 0;
}
