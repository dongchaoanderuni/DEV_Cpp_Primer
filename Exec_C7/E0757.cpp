#include <iostream>
#include <typeinfo>
#include <vector>
#include "Variable.h"
#include <string>
// #include "Sales_data.h"


using namespace std;

class Account
{
public:
    Account() = default;
    Account(const string &s, double amt): owner(s), amount(amt)  {}
    void calculate() { amount += amount * interestRate; }
    double balance() { return amount; }

    static double rate() { return interestRate; }
    static void rate(double newRate) {interestRate = newRate;} 

private:
    std::string owner;
    double amount = 0.0;
    static double interestRate;
    static double initRate() {return 0.0255;}
    static const std::string accountType;
    static constexpr int period = 30;
    double daily_tbl[period];
};

constexpr int Account::period;
double Account::interestRate = initRate();

int main()
{

    return 0;
}
