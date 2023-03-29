#include <iostream>

using namespace std;

int main(void)
{
    const int num = 20;
    const int &ref = num;
    const int &ref2 = 50;

    cout << ref2 << endl;

    const int *ptr = &num;
    const int *&refptr = ptr;

    *refptr++;
    cout << num << endl;

    return 0;
}