#include <iostream>

using namespace std;

struct student {
    string name;
    int age;
    float gpa;
};

int main(void)
{
    student stu = {.name="John Doe", .age=20, .gpa=3.5};

    cout << "Name: " << stu.name << endl;
    cout << "Age: " << stu.age << endl;
    cout << "GPA: " << stu.gpa << endl;
}