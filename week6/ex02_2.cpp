#include <iostream>
#include <cstring>

using namespace std;

class First
{
private:
    char* strOne;
public:
    First(char* str)
    {
        strOne = new char[strlen(str) + 1];
    }

    virtual ~First()
    {
        cout << "~First()" << endl;
        delete[] strOne;
    }
};

class Second: public First
{
private:
    char* strTwo;
public:
    Second(char* str1, char* str2): First(str1)
    {
        strTwo = new char[strlen(str2) + 1];
    }

    // virtual ~First() 라는 부모 클래스의 소멸자 정의에 따라 virtual로 유도됨.
    ~Second()
    {
        cout << "~Second()" << endl;
        delete[] strTwo;
    }
};

int main(void)
{
    First* ptr = new Second("simple", "complex");
    delete ptr;
    return 0;
}