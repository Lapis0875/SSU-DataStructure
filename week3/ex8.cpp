#include <iostream>

using namespace std;

class Person {
public:
    // 멤버 변수
    string name;
    int age;

    // 멤버 함수
    void introduce() {
        cout << "Hi, my name is " << name << " and I am " << age << " years old." << endl;
    }
};

int main(void)
{
    Person p1 = {.name="John", .age=20};
    p1.introduce();

    Person p2;
    p2.name = "Jane";
    p2.age = 25;
    p2.introduce();

    Person p3;
    p3.introduce();
}