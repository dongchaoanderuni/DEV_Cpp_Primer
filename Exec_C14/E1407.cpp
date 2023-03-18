#include "Print.h"
#include <cstring>
#include "SelfString.h"

using namespace std;

#define LegalInput (2)

// ostream &print(ostream &os, const String &s)
// {
// 	auto p = s.begin();
// 	while (p != s.end())
// 		os << *p++ ;
// 	return os;
// }

// ostream &operator<<(ostream &os, const String &s)
// {
// 	return print(os, s);
// }

allocator<char> String::alloc;

int main(int argc, char **argv)
{
    
    vector<String> vecStr;
    String str("a");
    String strZwei("ab");
    String strDrei("abc");
    
    vecStr.push_back(str);
    vecStr.push_back(strZwei);
    vecStr.push_back(strDrei);

    cout << str << endl;
    cout << strZwei << endl;
    cout << strDrei << endl;

    // for(auto ele:vecStr)
    // {
    //     cout << ele << " ";
    // }
    // cout << endl;

    return 0;
}
