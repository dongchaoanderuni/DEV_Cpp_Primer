#include "Headfile.h"

using namespace std;

class Person {
public:
    Person(std::string n, int a) : name(n), age(a) {}
private:
    std::string name;
    int age;
};

int main() {
    std::shared_ptr<Person> p = std::make_shared<Person>("John", 30);
}
