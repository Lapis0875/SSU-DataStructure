#include <iostream>

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

    void printName() {
        cout << "My name is " << this->name << endl;
    }
};


int main(void)
{
    Person person("John");
    person.printName();
    return 0;
}