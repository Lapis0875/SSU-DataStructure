#include <iostream>
using namespace std;

int main() {
  char name[100], lang[200];

  cout << "이름은 무엇입니까? > ";
  cin >> name;

  cout << "지금 배우는 프로그래밍 언어는 무엇입니까? > ";
  cin >> lang;

  cout << "제 이름은 " << name << "입니다." << endl;
  cout << "지금 배우는 프로그래밍 언어는 " << lang << "입니다." << endl;
  return 0;
}