#include "Print.h"
#include "StrBlob.h"

using namespace std;

struct destination
{
    int destinate{0};
};

struct connection
{   
    int destinate{0};
    int source{0};
};

connection connect(destination *dst)
{
    connection tmpConnect;
    cout << tmpConnect.destinate << endl;

    tmpConnect.destinate = dst->destinate;
    cout << tmpConnect.destinate << endl;

    return tmpConnect;
}

void disconnect(connection &tmpConnect) 
{
    tmpConnect.destinate = 0;
    tmpConnect.source = 0;
    

    return;
}

void endconnection(connection *pTmpConnect) 
{ 
    cout << pTmpConnect->destinate << endl;
    disconnect(*pTmpConnect);
    cout << pTmpConnect->destinate << endl;
    return;
}

void f(destination &tmpDestinate)
{
    connection c = connect(&tmpDestinate);
    shared_ptr<connection> p(&c, endconnection);
}


#define LegalInput (2)

int main()
{

    destination tmpDestinate{5};

    f(tmpDestinate);    


    return 0;
}
