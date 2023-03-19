#ifndef __OVERLOADSEARCH_H__
#define __OVERLOADSEARCH_H__

using namespace std;

class Base
{
public:
    virtual int fcn();

protected:

private:
};

int Base::fcn()
{
    return 0;
}

class D1:public Base
{
public:
    int fcn() override;
    virtual void f2();
protected:

private:

};

int D1::fcn()
{
    return 0;
}

void D1::f2()
{
    return;
}

class D2: public D1
{
public:
    int fcn(int);
    int fcn() override;
    void f2() override;
protected:

private:

};

int D2::fcn()
{
    return 0;
}

void D2::f2()
{
    return;
}

#endif