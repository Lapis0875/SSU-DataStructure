#include <iostream>

using namespace std;

class First
{
public:
    virtual void MyFunc()
    {
        cout << "First Func" << endl;
    }
};

class Second: public First
{
public:
    virtual void MyFunc()
    {
        cout << "Second Func" << endl;
    }
};

class Third: public Second
{
public:
    virtual void MyFunc()
    {
        cout << "Third Func" << endl;
    }
};

int main(void)
{
    Third* tptr = new Third();
    Second* sptr = tptr;
    First* fptr = sptr;


    // virtual로 선언된 MyFunc는 변수가 어떤 타입이든간에 원본 타입인 Third의 MyFunc()를 참조한다.
    fptr->MyFunc();
    sptr->MyFunc();
    tptr->MyFunc();

    tptr->MyFunc

    delete tptr;
    
    return 0;
}