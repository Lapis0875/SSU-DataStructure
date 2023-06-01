#include <iostream>
#define MAX_LIST_SIZE 100

using namespace std;

inline void error (char* str) {
    cout << stderr << str << endl;

    exit(1);
}

/**
 * @brief 동적 할당 기반의 스택에서 사용할 노드 클래스.
 * 
 * @tparam T 노드가 저장할 데이터의 타입.
 */
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(char data): data(data), next(nullptr) {}
};

/**
 * @brief Node<T>를 동적할당해 사용하는 스택 클래스.
 * 
 * @tparam T 노드가 저장할 데이터의 타입.
 */
template <typename T>
class Stack
{
private:
    Node<T>* top;
public:
    Stack() : top(nullptr) {}
    ~Stack() {
        // cout << "Stack<" << typeid(T).name() << "> 소멸자 호출." << endl;    // checkBracket(str) 종료될 때 알아서 호출되네요
        Node<T>* cur = top;
        while (cur != nullptr) {
            Node<T>* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }

    /**
     * @brief 현재 스택이 비어있는지 확인함.
     * 
     * @return true 스택이 비어 있음.
     * @return false 스택이 비어 있지 않음.
     */
    bool isEmpty()
    {
        return top == nullptr;
    }

    /**
     * @brief 스택에 새 요소를 삽입함.
     * 
     * @param e 새 요소.
     */
    void push(T e)
    {
        Node<T>* node = new Node<T>(e);
        node->next = top;
        top = node;
    }

    /**
     * @brief 스택에서 최상위 요소를 꺼냄.
     * 
     * @return T 스택의 최상위 요소.
     */
    T pop()
    {
        if (isEmpty()) {
            cout << "스택이 비어 있습니다." << endl;
            exit(1);
        }

        T data = top->data;
        Node<T>* node = top;

        top = top->next;
        delete node;
        return data;
    }

    /**
     * @brief 스택에서 최상위 요소를 확인함.
     * 
     * @return T 스택의 최상위 요소.
     */
    T peek()
    {
        if (isEmpty()) {
            cout << "스택이 비어 있습니다." << endl;
            exit(1);
        }
        return top->data;
    }
};

/**
 * @brief 스택을 활용한 괄호 검사 알고리즘. 왼쪽 괄호들을 스택에 담아, 오른쪽 괄호를 만나면 스택에서 하나씩 꺼내서 비교한다.
 * 
 * @param str 괄호를 검사할 문자열.
 * @return true 모든 괄호가 올바르게 짝이 맞는다.
 * @return false 한 괄호라도 짝이 맞지 않는다.
 */
bool checkBracket(string str)
{
    Stack<char> stack;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (stack.isEmpty())
                return false;
            char top = stack.pop();
            if (
                (ch == ')' && top != '(')
                || (ch == '}' && top != '{')
                || (ch == ']' && top != '[')
            )
                return false;
        }
    }
    return stack.isEmpty();
}

int main(void)
{
    string str = "{(a+b)*c}-d";

    if (checkBracket(str)) {
        cout << str << " : 괄호가 맞습니다." << endl;
    }
    else {
        cout << str << " : 괄호가 틀렸습니다." << endl;
    }

    return 0;
}