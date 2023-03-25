#include "Headfile.h"
#include "TemplateScreen.h"

using namespace std;

int main() 
{
    Screen<5,3> myScreen;
    myScreen.display(cout);

    myScreen.move(4,0).set('#');

    Screen<5,5> nextScreen('X');
    nextScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    nextScreen.display(cout);
    cout << endl;

    const Screen<5,3> blank;
    myScreen.set('#').display(cout);
    cout << endl;
    blank.display(cout);
    cout << endl;

    cin >> myScreen;
    cout << myScreen << endl << nextScreen << endl ;


    return 0;
}
