#include <iostream>
using namespace std;

int main() {
  int var1, var2, result;
  cout << "첫 번째 숫자 입력: ";
  cin >> var1;

  cout << "두 번째 숫자 입력: ";
  cin >> var2;

  result = var1 + var2;
  cout << "덧셈결과: " << result << endl;
  return 0;
}