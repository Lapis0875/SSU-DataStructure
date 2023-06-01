#include <iostream>
using namespace std;
class Parent 
{
    public:
        int data1;
        int data2;


        Parent(int data1, int data2) {
            this->data1 = data1;
            this->data2 = data2;
        }
        void print_data() {
            cout << "first data : " << this->data1 << "\nsecond data : " << this->data2 << "\n";
        }
};

class Child : public Parent 
{
    public:
        Child(int data1, int data2) : Parent(data1, data2) {}
        
        void swap() 
        {
            int tmp = data1;
            data1 = data2;
            data2 = tmp;
        }
};

int main() {
  Child c1(1, 2);
  c1.print_data();
  c1.swap();
  c1.print_data();
}