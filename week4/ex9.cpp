#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Person
{
private:
    char name[50];
    int age;
public:
    Person(int myage, char* myname) : age(myage)
    {
        strcpy(name, myname);
    }

    void WhatYourName() const
    {
        cout << "My name is " << name << endl;
    }

    void HowOldAreYou() const
    {
        cout << "I'm " << age << " years old" << endl;
    }
};

class UnivStudent : public Person
{
private:
    char major[50];
public:
    UnivStudent(int myage, char* myname, char* mymajor) : Person(myage, myname)
    {
        strcpy(major, mymajor);
    }

    void WhoAreYou() const
    {
        WhatYourName();
        HowOldAreYou();
        cout << "My major is " << major << endl << endl;
    }
};

int main(void)
{
    UnivStudent u1(22, "Kim", "Computer eng.");
    u1.WhoAreYou();

    UnivStudent u2(21, "Yoon", "Software eng.");
    u2.WhoAreYou();

    UnivStudent* u3 = new UnivStudent(23, "Choi", "Math");
    u3->WhoAreYou();
    return 0;
}