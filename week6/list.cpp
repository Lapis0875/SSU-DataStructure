#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T value;
    Node<T>* next;
    
    Node(T element): value(element)
    {
        next = nullptr;
    }
};

template <typename T>
class List<T>
{
private:
    Node<T>* head;
    Node<T>* tail;
public:
    List()
    {
        head = nullptr;
        tail = nullptr;
    }

    List(T arr[])
    {
        for (T e: arr)
        {
            append(e);
        }
    }

    void append(T element)
    {
        Node<T>* n = new Node<T>(element);
        if (head == nullptr)
        {
            head = n;
            tail = head;
        }
        else
        {
            tail.next = n;
            tail = n;   // move tail
        }
    }
};

int main(void)
{
    List<int> l();
    l.append(1);
    l.append(2);
    return 0;
}