#include <iostream>

using namespace std;

template <typename T>
class Node
{
    Node<T>* prev;
    Node<T>* next;
    T data;
public:
    Node(T val): data(val), prev(nullptr), next(nullptr) {}

    Node<T>* getPrev()
    {
        return prev;
    }

    Node<T>* getNext()
    {
        return next;
    }

    void setPrev(Node<T>* prev)
    {
        prev = prev;
    }

    void setNext(Node<T>* next)
    {
        next = next;
    }

    void display()
    {
        cout << "<" << data << "> ";
    }

    bool hasData(T val)
    {
        return data == val;   
    }

    void insertNext(Node<T>* n)
    {
        if (n != nullptr)
        {
            n->prev = this;
            n->next = next;
            if (next != nullptr)
                next->prev = n;
            next = n;
        }
    }

    Node<T>* remove()
    {
        if (prev != nullptr)
            prev->next = next;
        if (next != nullptr)
            next->prev = prev;
        return this;
    }
};

template <typename T>
class DoubleLinkedList
{
private:
    Node<T> org;
public:
    DoubleLinkedList(void) : org(0) {}
    
    ~DoubleLinkedList()
    {
        clear();
    }

    /**
     * @brief 리스트를 초기화함.
     */
    void clear()
    {
        while(!isEmpty())
            delete remove(0);
    }

    Node<T>* getHead()
    {
        return org.getNext();
    }

    /**
     * @brief 현재 리스트가 비어있는지 확인함.
     * 
     * @return true 리스트가 비어 있음.
     * @return false 리스트가 비어 있지 않음.
     */
    bool isEmpty()
    {
        return getHead() == nullptr;
    }

    /**
     * @brief 주어진 위치의 요소를 반환함.
     * 
     * @param pos 요소의 위치.
     */
    Node<T>* getEntry(int pos)
    {
        Node<T>* n = &org;
        for (int i = -1; i < pos; i++, n = n->getNext())
            if (n == nullptr)
                break;
        return n;
    }

    /**
     * @brief 주어진 위치에 새 요소를 삽입함.
     * 
     * @param pos 새 요소를 삽입할 위치.
     * @param e 새 요소.
     */
    void insert(int pos, Node<T>* n)
    {
        Node<T>* prev = getEntry(pos - 1);
        if (prev != nullptr)
            prev->insertNext(n);     
    }

    Node<T>* remove(int pos)
    {
        Node<T>* n = getEntry(pos);
        return n->remove();
    }

    /**
     * @brief 주어진 요소가 리스트 내에 존재하는지 검사함.
     * 
     * @param item 검사할 요소.
     * @return true 주어진 요소가 리스트 내부에 존재함.
     * @return false 주어진 요소가 리스트 내부에 존재하지 않음.
     */
    Node<T>* find(T val)
    {
        for (Node<T>* p = getHead(); p != nullptr; p = p->getNext())
            if(p->hasData(val)) return p;
        return nullptr;
    }

    void replace(int pos, Node<T>* n)
    {
        Node<T>* prev = getEntry(pos-1);
        if (prev != nullptr)
        {
            delete prev->getNext()->remove();
            prev->insertNext(n);
        }
    }

    /**
     * @brief 리스트의 길이를 반환함.
     * 
     * @return int 리스트의 길이.
     */
    int size()
    {
        int count = 0;

        for (Node<T>* p = getHead(); p != nullptr; p = p->getNext())
            count++;

        return count;
    }

    /**
     * @brief 리스트의 원소를 모두 출력함.
     */
    void display()
    {
        cout << "[이중연결리스트의 항목 수 = " << size() << "] : ";

        for (Node<T>* p = getHead(); p != nullptr; p = p->getNext())
            p->display();

        cout << endl;
    }
};

int main(void)
{
    DoubleLinkedList<int> list;

    list.insert(0, new Node<int>(10));
    list.insert(0, new Node<int>(20));
    list.insert(1, new Node<int>(30));
    list.insert(list.size(), new Node<int>(40));
    list.insert(2, new Node<int>(50));
    list.display();

    list.remove(2);
    list.remove(list.size() - 1);
    list.remove(0);
    list.replace(1, new Node<int>(90));
    list.display();

    list.clear();
    list.display();
    return 0;
}