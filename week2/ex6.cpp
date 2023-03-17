#include <iostream>
#define SUB(x, y) ((x) - (y))
#define PRT(x) (cout << #x << "의 값: " << x << endl)
using namespace std;

inline int sub(int x, int y) {
  return x - y;
}

inline void prt(int x) {
  cout << "prt(x): " << x << endl;
}

int main() {
  int result;
  int num1 = 15, num2 = 7;
  result = sub(num1, num2);
  prt(result);
  return 0;
}