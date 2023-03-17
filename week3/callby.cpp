#include <iostream>

using namespace std;

void swapByValue(int num1, int num2)
{
    int temp = num2;
    num2 = num1;
    num1 = temp;
    // Call By Value, 원본 변경 X
}

void swapByRefPtr(int*, int*);
void swapByRefVar(int &a, int &b);

int main(void)
{
    int val1 = 10, val2 = 20;
    // pre-check
    cout << "val1: " << val1 << endl;
    cout << "val2: " << val2 << endl;

    swapByValue(val1, val2);
    // check 1
    cout << "val1: " << val1 << endl;
    cout << "val2: " << val2 << endl;

    swapByRefPtr(&val1, &val2);
    // check 2
    cout << "val1: " << val1 << endl;
    cout << "val2: " << val2 << endl;

    swapByRefVar(val1, val2);
    // check 3
    cout << "val1: " << val1 << endl;
    cout << "val2: " << val2 << endl;

}

void swapByRefPtr(int *num1, int *num2)
{
    int temp = *num2;
    *num2 = *num1;
    *num1 = temp;
    // Call By Reference (포인터 사용), 원본 변경 O
}

void swapByRefVar(int &num1, int &num2)
{
    int temp = num2;
    num2 = num1;
    num1 = temp;
    // Call By Reference (참조자 사용), 원본 변경 O
}