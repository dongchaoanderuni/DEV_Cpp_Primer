#ifndef TESTEQISNTANCE_H
#define TESTEQISNTANCE_H

using namespace std;

class TestEqInstance
{
public:
    TestEqInstance(int value=0):val(value) {}
    bool operator()(int value) const{return val == value;}

private:
    int val;
};

#endif
