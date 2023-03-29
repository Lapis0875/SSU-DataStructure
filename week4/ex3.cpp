#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Person {
private:
    char name[20];
public:
    Person(const char* name) {
        strcpy(this->name, name);
    }

    ~Person() {
        cout << name << " is being destroyed." << endl;
    }

    void sayHello() {
        cout << "Hello, my name is " << name << "." << endl;
    }
};


int main(void)
{
    Person person("John");
    person.sayHello();
    return 0;
}