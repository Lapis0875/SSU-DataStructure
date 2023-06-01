#include <iostream>

using namespace std;

class First
{
public:
    void MyFunc()
    {
        cout << "First Func" << endl;
    }
};

class Second: public First
{
public:
    void MyFunc()
    {
        cout << "Second Func" << endl;
    }
};

class Third: public Second
{
public:
    void MyFunc()
    {
        cout << "Third Func" << endl;
    }
};

int main(void)
{
    Third* tptr = new Third();
    Second* sptr = tptr;
    First* fptr = sptr;

    // 실제 tptr이 가리키는 Third의 객체가 아니라, 각각의 포인터 타입에 해당하는 구현부를 호출함.
    // Q1. 실제로 tptr이 가리키는 메모리에 있는 객체는 타입 정보를 가지고 있지 않은가?
    // Q2. 가지고 있다면, 왜 자기 타입의 멤버를 참조하지 않고 변수의 타입에 따라 멤버를 참조하는가?
    // Q3. 혹시 이는 C++의 멤버 탐색 시스템에 관련이 있는가?
    fptr->MyFunc();
    sptr->MyFunc();
    tptr->MyFunc();

    delete tptr;
    
    return 0;
}