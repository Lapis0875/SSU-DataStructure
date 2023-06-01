#include <iostream>
#include <utility>

using namespace std;

int main(void)
{
    pair<int, double> myPair(10, 3.14);

    cout << "First value: " << myPair.first << endl;
    cout << "Second value: " << myPair.second << endl;

    myPair.first = 20;
    myPair.second = 2.71;
    cout << "Modified first value: " << myPair.first << endl;
    cout << "Modified second value: " << myPair.second << endl;

    return 0; 
}