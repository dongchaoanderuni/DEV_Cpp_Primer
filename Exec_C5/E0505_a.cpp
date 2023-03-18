#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

#define IllegalLowGrade     (0)
#define IllegalHighGrade    (100)
#define LowGrade            (50)
#define Minus               (3)
#define Major               (7)

int main()
{
    vector<string> grades{"F","D", "C", "B", "A", "A++"};
    int score{0};


    while(cin >> score)
    {
        if((score < IllegalLowGrade)
            ||(score > IllegalHighGrade))
        {
            cout << "Illegal input, please check it. " << endl;
        }
        else if(score < LowGrade)
        {
            cout << "Score:\t" << score;
            cout << "\t Grade:\t" << grades[0] << endl;
        }
        else if(score == IllegalHighGrade)
        {
            cout << "Score:\t" << score;
            cout << "\t Grade:\t" << grades[(score-50)/10]<< endl;
        }   
        else
        {
            cout << "Score:\t" << score;
            cout << "\t Grade:\t" << grades[(score-50)/10];
            if((score%10) <= Minus)
            {
                cout<< "-";
            }
            else if((score%10) >= Major )
            {
                cout << "+";
            }
            cout << endl;
        }

    }

    return 0;
}