#include <iostream>

using namespace std;

class Person {
public:
    // 멤버 변수
    string name;
    int age;

    // 멤버 함수
    void print() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

struct Car {
    string make;
    string model;
    int year;
};

int main(void)
{
    Person p1 = {.name="Alice", .age=25};
    p1.print();

    Car c1 = {"Toyota", "Camry", 2021};
    cout << "Make: " << c1.make << endl;
    cout << "Model: " << c1.model << endl;
    cout << "Year: " << c1.year << endl;
}