#include <iostream>

using namespace std;

void swapByRef(int &num1, int &num2)
{
    int temp = num2;
    num2 = num1;
    num1 = temp;
    // Call By Reference (참조자 사용), 원본 변경 O
}

int main(void)
{
    int val1 = 10, val2 = 20;

    swapByRef(val1, val2);
    cout << "val1: " << val1 << endl;
    cout << "val2: " << val2 << endl;

}