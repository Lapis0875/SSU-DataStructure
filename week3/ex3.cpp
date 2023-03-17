#include <iostream>

using namespace std;

int main(void)
{
    int num = 12;           // int형 변수
    int *ptr = &num;        // int*형 변수 (포인터)
    int **dptr = &ptr;      // int**형 변수 (포인터)

    int &ref = num;         // int형 변수 num에 대한 참조자
    int *(&pref) = ptr;     // int*형 변수 ptr에 대한 참조자
    int **(&dpref) = dptr;  // int**형 변수 dptr에 대한 참조자

    cout << ref << endl;        // int형 변수 num에 대한 참조자 ref를 사용해, num의 값을 출력.
    cout << *pref << endl;      // int*형 변수 ptr에 대한 참조자 pref를 사용해, *ptr (== num) 의 값을 출력.
    cout << **dpref << endl;    // int**형 변수 dptr에 대한 참조자 dpref를 사용해, **dptr (== num) 의 값을 출력.
}