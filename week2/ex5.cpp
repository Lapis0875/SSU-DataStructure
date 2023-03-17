#include <iostream>
using namespace std;

int MyFunc(char c);
int MyFunc(int i);
int MyFunc(int i1, int i2);
// void MyFunc(int i);    // 반환형만 다른 경우는 오버로딩 정의를 충족하지 못해.

int addOne(int num = 0);
int add(int num1 = 0, int num2 = 0);
int mul(int num1 = 0, int num2 = 1, int num3 = 1);

int main() {
  cout << "1 + 2 = " << addOne(2) << endl;

  cout << "3 + 5 = " << add(3, 5) << endl;

  cout << "0 + 1 = " << addOne() << endl;
  cout << "0 + 0 = " << add() << endl;
  
  cout << "1 * 2 * 3 = " << mul(1, 2, 3) << endl;
  cout << "1 * 2 = " << mul(1, 2) << endl;
  cout << "1 = " << mul(1) << endl;
  return 0;
}

int addOne(int num) {
  return num + 1;
}

int add(int num1, int num2)
{
  return num1 + num2;
}

int mul(int num1, int num2, int num3)
{
  return num1 * num2 * num3;
}