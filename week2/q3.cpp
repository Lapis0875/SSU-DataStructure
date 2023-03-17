#include <iostream>
using namespace std;

int main() {
  int var1, var2, result = 0;
  cout << "두 개의 숫자 입력: ";
  cin >> var1 >> var2;

  if (var1 < var2)
    for (int i = var1 + 1; i < var2; i++)
      result += i;
  else
    for (int i = var2 + i; i < var1; i++)
      result += i;

  cout << "두 수 사이의 정수의 합 " << result << endl;
  return 0;
}