#include <iostream>

using namespace std;

inline void error (char* str) {
    cout << stderr << str << endl;

    exit(1);
}

template <typename T>
class Node
{
private:
    T data;
    Node<T>* next;
public:
    Node(T val): data(val), next(NULL) {}
    
    Node<T>* getLink()
    {
        return next;
    }

    void setLink(Node<T>* next)
    {
        next = next;
    }

    void display()
    {
        cout << data << endl;
    }

    bool hasData(int val)
    {
        return data == val;
    }

    void insertNext(Node<T>* n)
    {
        // 자기 바로 뒤에 새 노드를 삽입.
        n->next = next;     // 자신이 가리키던 노드를 새 노드가 가리키게 변경
        next = n;           // 자신은 새 노드를 가리키게 변경
    }

    Node<T>* removeNext()
    {
        Node<T>* removed = next;
        if (removed != NULL)    // 만약 현재 노드가 가리키는 노드가 있으면
        {
            // 현재 노드가 다음 노드가 가리키던 노드를 가리키게 변경
            next = removed->next;
        }
        return removed;
    }
};

template <typename T>
class LinkedList
{
private:
    Node<T> org;
    int length;
public:
    LinkedList(void) : org(0) {}
    
    ~LinkedList()
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
        return org.getLink();
    }

    /**
     * @brief 현재 리스트가 비어있는지 확인함.
     * 
     * @return true 리스트가 비어 있음.
     * @return false 리스트가 비어 있지 않음.
     */
    bool isEmpty()
    {
        return getHead() == NULL;
    }

    /**
     * @brief 주어진 위치의 요소를 반환함.
     * 
     * @param pos 요소의 위치.
     */
    Node<T>* getEntry(int pos)
    {
        Node<T>* n = &org;
        for(int i = -1; i < pos; i++, n = n->getLink())     // 헤드 노드 (org) 부터 동작하므로, pos + 1번 반복해야함. 따라서 i가 -1에서 시작.
            if (n == NULL) break;
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
        Node<T>* prev = getEntry(pos-1);
        if (prev != NULL)
            prev->insertNext(n);
    }

    /**
     * @brief 주어진 위치의 요소를 삭제함.
     * 
     * @param pos 요소를 삭제할 위치.
     */
    Node<T>* remove(int pos)
    {
        Node<T>* prev = getEntry(pos-1);
        return prev->removeNext();
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
        for (Node<T>* p = getHead(); p != NULL; p = p->getLink())
            if(p->hasData(val)) return p;
        return NULL;
    }

    /**
     * @brief 주어진 위치의 요소를 새 요소로 대체함.
     * 
     * @param pos 대체할 요소의 위치.
     * @param e 새 요소.
     */
    void replace(int pos, Node<T>* n)
    {
        Node<T>* prev = getEntry(pos - 1);
        if (prev != NULL)
            delete prev->removeNext();
            prev->insertNext(n);
    }

    /**
     * @brief 리스트의 길이를 반환함.
     * 
     * @return int 리스트의 길이.
     */
    int size()
    {
        int count = 0;

        for (Node<T>* p = getHead(); p != NULL; p = p->getLink())
            count++;
        
        return count;
    }

    /**
     * @brief 리스트의 원소를 모두 출력함.
     */
    void display()
    {
        cout << "단순연결리스트의 전체 항목의 개수 = " << size() << endl;
        for (Node<T>* p = getHead(); p != NULL; p = p->getLink())
        {
            p->display();
        }
        cout << endl;
    }
};

int main(void)
{
    LinkedList<int> list;

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