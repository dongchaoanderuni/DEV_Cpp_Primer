#include "Headfile.h"

using namespace std;

struct divide
{
    int operator()(int denominator, int divisor){return denominator / divisor;}
};

int add(int i, int j) {return i+j;}

auto mod = [](int i, int j){return i%j;};

int main()
{
    map<string, int(*)(int,int)> binops;
    
    // function<int(int, int)> pfuncAdd = add;
    // function<int(int, int)> pfuncSub = minus<int>();
    // function<int(int, int)> pfuncDivide = divide();
    // function<int(int, int)> pfuncMod = mod;

    // binops.insert({"+", add});
    // binops.insert({"-", minus<int>()});
    // binops.insert({"/", divide()});
    // binops.insert({"%", mod});
    // binops["*"] = [](int i,int j){return i*j;};


    binops["+"] = add ;
    // binops["-"] = minus<int>();
    // binops["/"] = divide();
    binops["%"] = mod ;
    binops["*"] = [](int i,int j){return i*j;};


    // Test with some values
    int x = 2, y = 3;
    for (const auto &p : binops) {
    cout << x << " " << p.first << " " << y << " = " << p.second(x, y)
                << endl;
    }

    return 0;
}