#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node(T val): data(val), next(NULL) {}
};

template <typename T>
class CircularLinkedList
{
private:
    Node<T>* tail;
    int size;
public:
    CircularLinkedList(void) : tail(NULL), size(0) {}

    void add(T value)
    {
        Node<T>* new_node = new Node<T>(value);

        if (tail == NULL)
        {
            tail = new_node;
            tail->next = tail;
        }
        else
        {
            new_node->next = tail->next;
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    void remove(T value)
    {
        if (tail == NULL)
            return;
        
        Node<T>* current = tail->next;
        Node<T>* prev = tail;

        do {
            if (current->data == value) {
                prev->next = current->next;
                if (current == tail)
                    tail = prev;
                
                delete current;
                size--;
                return;
            }

            prev = current;
            current = current->next;
        } while (current != tail->next);
    }

    /**
     * @brief 리스트의 원소를 모두 출력함.
     */
    void display()
    {
        cout << "순환연결리스트의 전체 항목의 개수 = " << get_size() << endl;

        if (tail == NULL)
            return;

        Node<T>* current = tail->next;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != tail->next);
        cout << endl;
    }

    /**
     * @brief 리스트의 길이를 반환함.
     * 
     * @return int 리스트의 길이.
     */
    int get_size()
    {
        return size;
    }
};

int main(void)
{
    CircularLinkedList<int> list;

    list.add(1);
    list.add(2);
    list.add(3);
    list.display();
    
    list.remove(2);
    list.display();
    return 0;
}