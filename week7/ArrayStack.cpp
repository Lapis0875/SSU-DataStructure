#include <iostream>
#define MAX_LIST_SIZE 100

using namespace std;

inline void error (char* str) {
    cout << stderr << str << endl;

    exit(1);
}

template <typename T>
class ArrayStack
{
private:
    T data[MAX_LIST_SIZE];
    int top;
public:
    ArrayStack() : top(-1) {}
    ~ArrayStack() {}

    /**
     * @brief 현재 스택이 비어있는지 확인함.
     * 
     * @return true 스택이 비어 있음.
     * @return false 스택이 비어 있지 않음.
     */
    bool isEmpty()
    {
        return top == -1;
    }

    /**
     * @brief 현재 스택이 가득 차 있는지 확인함.
     * 
     * @return true 스택이 가득 차 있음.
     * @return false 스택이 가득 차 있지 않음.
     */
    bool isFull()
    {
        return top == MAX_LIST_SIZE - 1;
    }

    /**
     * @brief 스택에 새 요소를 삽입함.
     * 
     * @param e 새 요소
     */
    void push(T e)
    {
        data[++top] = e
    }

    /**
     * @brief 스택의 최상위 요소를 꺼냄.
     * 
     * @return T 스택의 최상위 요소.
     */
    T pop()
    {
        if (isEmpty()) {
            error("스택이 비어 있습니다.");
            return NULL;
        }
        return data[top--];
    }

    /**
     * @brief 스택의 최상위 요소를 꺼내지 않고 값만 가져옴.
     * 
     * @return T 스택의 최상위 요소.
     */
    T peek()
    {
        if (isEmpty()) {
            error("스택이 비어 있습니다.");
            return;
        }
        return data[top];
    }

    /**
     * @brief 스택의 원소를 모두 출력함.
     */
    void display()
    {
        cout << "[ 스택 항목의 수 = " << top + 1 << " ] ==> ";
        for (int i = 0; i <= top; i++) {
            cout << "<" << data[i] << "> ";
        }
        cout << endl;
    }


    /**
     * @brief 스택을 초기화함.
     */
    void clear()
    {
        top = -1;
    }
};

int main(void)
{
    ArrayStack<int> stack;

    for (int i = 0; i < 10; i++)
        stack.push(i);
    
    stack.display();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();
    
    return 0;
}