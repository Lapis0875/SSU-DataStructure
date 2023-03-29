#include <cstdio>

struct Person {
    char name[20];
    int age;

    void introduce()
    {
        printf("Hello, my name is %s and I am %d years old.\n", name, age);
    }
};

int main(void)
{
    Person p = {"Myungsoo", 21};
    p.introduce();
}