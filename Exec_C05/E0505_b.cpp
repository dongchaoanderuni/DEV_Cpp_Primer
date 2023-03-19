#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

#define IllegalLowGrade     (0)
#define HighGrade    (100)
#define LowGrade            (50)
#define Minus               (3)
#define Major               (7)

int main()
{
    vector<string> grades{"F","D", "C", "B", "A", "A++"};
    int score{0};


    while(cin >> score)
    {
        cout<<(((score>HighGrade)||(score<IllegalLowGrade))?"Illegal input, please check it.":
            (score==HighGrade)?"A++":(score<LowGrade)?"F":((score-50)%10 >= Major)?
            (grades[(score-50)/10]+"+"):((score-50)%10 <= Minus)?(grades[(score-50)/10]+"-"):(grades[(score-50)/10]))<<endl;
    }

    return 0;
}