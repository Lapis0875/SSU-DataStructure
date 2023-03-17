#include <iostream>

using namespace std;

int main(void)
{
    int val1 = 10;
    int *val2 = new int;
    cout << "val2 (newly allocated in heap) : " << *val2 << endl;
}