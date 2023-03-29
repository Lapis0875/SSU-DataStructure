#include <iostream>

using namespace std;

class Box {
    private:
        int value;
    public:
        string label;

        Box(string label, int value) {
            this->label = label;
            this->value = value;
        }

        Box(int value) {
            this->value = value;
            this->label = "";
        }

        void editLabel(string newLabel) {
            this->label = newLabel;
        }

        int unpack() {
            return this->value;
        }

        void peek();    // 사전에 클래스 멤버로 먼저 정의해야함
};

void Box::peek() {
    // 클래스 코드블럭 밖임에도 클래스 내부와 같은 context를 공유.
    cout << "Box<" << label << ">" "(" << value <<  ")" << endl;
}


int main(void)
{
    Box b(42);
    b.peek();
    b.editLabel("Hello");
    b.peek();
    cout << b.unpack() << endl;
    return 0;
}