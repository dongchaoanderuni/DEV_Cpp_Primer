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

void disconnect(connection *tmpConnect) 
{
    // cout << "disconnect" << endl;
    // cout << tmpConnect.destinate << endl;
    // cout << tmpConnect.source << endl;

    // tmpConnect.destinate = 0;
    // tmpConnect.source = 0;

    tmpConnect -> destinate = 0;
    tmpConnect -> source = 0;

    // cout << tmpConnect.destinate << endl;
    // cout << tmpConnect.source << endl;


    return;
}

void endconnection(connection *pTmpConnect) 
{ 
    cout << "endconnection" << endl;
    cout << pTmpConnect->destinate << endl;
    disconnect(pTmpConnect);
    // cout << "endconnection" << endl;
    cout << pTmpConnect->destinate << endl;
    return;
}

void f(destination &tmpDestinate)
{
    connection c = connect(&tmpDestinate);
    shared_ptr<connection> p(&c, endconnection);
}

void fSharedPtrWithLamda(destination &tmpDestinate)
{
    connection c = connect(&tmpDestinate);
    shared_ptr<connection> p(&c, [](connection *p){disconnect(p);});
}

void fUniquePtr(destination &tmpDestinate)
{
    connection c = connect(&tmpDestinate);
    unique_ptr<connection, decltype(endconnection)*> pTmpConnect(&c, endconnection);

}

#define LegalInput (2)

int main()
{

    destination tmpDestinate{5};

    // f(tmpDestinate);    

    // cout << "fSharedPtrWithLamda" << endl;
    // fSharedPtrWithLamda(tmpDestinate);


    destination tmpDestinateZwei{10};

    // cout << "fUniquePtr" << endl;
    // fUniquePtr(tmpDestinate);

    // cout << "fUniquePtr" << endl;
    // fUniquePtr(tmpDestinateZwei);

    connection c = connect(&tmpDestinate);
    connection c = connect(&tmpDestinateZwei);
    unique_ptr<connection, decltype(endconnection)*> pTmpConnect(&c, endconnection);

    return 0;
}
s