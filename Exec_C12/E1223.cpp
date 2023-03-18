#include "Print.h"
#include "StrBlob.h"
#include <cstring>

using namespace std;


int main()
{
    char pCharEins[] = "afbiawhfipawjaoifenanwflenalfn;af!";
    char pCharZwei[] = "wafwa31awavk,f[3bapab[n]]";
    size_t length= strlen(pCharEins)+strlen(pCharZwei);
    char *p = new char[length+1];
    cout << length << endl;
    for(int index=0;index !=length;++index)
    {
        if(index < strlen(pCharEins))
        {
            p[index] = pCharEins[index];
        }
        else
        {
            p[index] = pCharZwei[index-strlen(pCharEins)];
        }
    }

    for(int index=0; index!=length;++index)
    {
        cout<< p[index];
    }
    cout << endl;

    delete []p;

    return 0;
    
}
