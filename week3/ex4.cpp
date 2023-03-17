#include <iostream>

using namespace std;

void swapByValue(int num1, int num2)
{
    int temp = num2;
    num2 = num1;
    num1 = temp;
    // Call By Value, 원본 변경 X
}

int main(void)
{
    int val1 = 10, val2 = 20;

    swapByValue(val1, val2);
    cout << "val1: " << val1 << endl;
    cout << "val2: " << val2 << endl;

}