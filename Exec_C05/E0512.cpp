#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>

using namespace std;

int main()
{
    char ch;
    int ffcount{0};
    int flcount{0};
    int ficount{0};
    
    while(cin >> ch)
    {
        
        switch(ch)
        {
            case('a'):
            {
                cout << "char:\t" << ch << '\t' << endl;
                break;
            }   
            case('e'):
            {
                cout << "char:\t" << ch << '\t' << endl;
                break;
            } 
            case('i'):
            {
                cout << "char:\t" << ch << '\t' << endl;
                break;
            }
            case('o'):
            {
                cout << "char:\t" << ch << '\t' << endl;
                break;
            }
            case('u'):
            {
                cout << "char:\t" << ch << '\t' << endl;
                break;
            }
            case('f'):
            {
                cout << "char:\t" << ch;
                cin >> ch;
                cout << ch << endl;
                switch(ch)
                {
                    case('f'):
                    {
                        ++ffcount;
                        break;
                    }
                    case('l'):
                    {
                        ++flcount;
                        break;
                    }
                    case('i'):
                    {
                        ++ficount;
                        break;
                    }
                    case(' '):
                    {
                        break;
                    }
                    case('\t'):
                    {
                        break;
                    }
                    case('\n'):
                    {
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }

    cout << "ffcount:\t" << ffcount << endl;
    cout << "flcount:\t" << flcount << endl;
    cout << "ficount:\t" << ficount << endl;

    return 0;
}