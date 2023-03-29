#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

class Person {
private:
    string name;
public:
    Person(const string& name) {
        this->name = name;
    }

    Person& setName(const string& name) {
        this->name = name;
        return *this;
    }

    Person& printName() {
        cout << "My name is " << this->name << endl;
        return *this;
    }
};


int main(void)
{
    Person person("John");
    person.printName().setName("Alice").printName().setName("Max").printName();
    return 0;
}