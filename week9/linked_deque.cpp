                                                                                                                                                #include <iostream>

using namespace std;

/**
 * @brief 연결 리스트를 구현하기 위한 노드 클래스
 * 
 * @tparam T 노드가 가지는 데이터의 타입
 */
template <typename T>
class Node
{
    Node<T>* prev;
    Node<T>* next;
    T data;
public:
    Node(T val) : data(val), prev(nullptr), next(nullptr) {}
    
    /**
     * @brief 이 노드가 가리키는 이전 노드의 주소를 가져옵니다.
     * 
     * @return Node<T>* 이 노드의 이전 노드의 주소.
     */
    Node<T>* getPrev()
    {
        return prev;
    }
    
    /**
     * @brief 이 노드가 가리키는 다음 노드의 주소를 가져옵니다.
     * 
     * @return Node<T>* 이 노드의 다음 노드의 주소.
     */
    Node<T>* getNext()
    {
        return next;
    }

    /**
     * @brief 이 노드의 이전 노드를 인자로 받은 노드를 가리키게 합니다.
     * 
     * @param next 가리킬 이전 노드의 주소.
     */
    void setPrev(Node<T>* prev)
    {
        this.prev = prev;
    }

    /**
     * @brief 이 노드의 다음 노드를 인자로 받은 노드로 가리키게 합니다.
     * 
     * @param next 가리킬 다음 노드의 주소.
     */
    void setNext(Node<T>* next)
    {
        this.next = next;
    }

    /**
     * @brief 이 노드의 정보를 콘솔에 출력함.
     */
    void display()
    {
        cout << " <" << data << ">";
    }

    /**
     * @brief 이 노드가 주어진 값을 가지고 있는지 검사합니다.
     * 
     * @param val 노드의 값과 비교할 값.
     * @return true 같은 값을 가지고 있음
     * @return false 그렇지 않음
     */
    bool hasData(T val)
    {
        return data == val;
    }

    /**
     * @brief 이 노드의 다음 노드로 인자로 받은 노드를 설정합니다.
     * 
     * @param n 새 노드
     */
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

    /**
     * @brief 이 노드의 이전 노드로 인자로 받은 노드를 설정합니다.
     * 
     * @param n 새 노드
     */
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

    /**
     * @brief 헤드 노드를 가져옵니다.
     * 
     * @return Node<T>* 헤드 노드의 주소
     */
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

    /**
     * @brief 주어진 위치의 노드를 제거합니다.
     * 
     * @param pos 위치
     * @return Node<T>* 제거된 노드의 주소
     */
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

    /**
     * @brief 주어진 위치의 노드를 교체합니다.
     * 
     * @param pos 위치
     * @param n 교체할 새 노드
     */
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
     * @brief 연결리스트의 길이를 반환함.
     * 
     * @return int 리스트의 길이
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

template <typename T>
class LinkedDeque : public DoubleLinkedList<T>
{
public:
    /**
     * @brief 덱의 앞에 새 노드를 추가합니다.
     * 
     * @param n 새 노드
     */
    void addFront(Node<T>* n)
    {
        this->insert(0, n);
    }
    
    /**
     * @brief 덱의 앞에 새 노드를 추가합니다.
     * 
     * @param val 새 노드의 값
     */
    void addFront(T val)
    {
        addFront(new Node<T>(val));
    }

    /**
     * @brief 덱의 전단에서 노드를 제거합니다.
     * 
     * @return Node<T>* 제거된 노드
     */
    Node<T>* deleteFront()
    {
        return this->remove(0);
    }

    /**
     * @brief 덱의 전단 노드를 가져옵니다.
     * 
     * @return Node<T>* 전단의 노드
     */
    Node<T>* getFront()
    {
        return this->getEntry(0);
    }

    /**
     * @brief 덱의 후단에 노드를 추가합니다.
     * 
     * @param n 새 노드
     */
    void addRear(Node<T>* n)
    {
        this->insert(this->size(), n);
    }

    /**
     * @brief 덱의 후단에 노드를 추가합니다.
     * 
     * @param n 새 노드의 값
     */
    void addRear(T val)
    {
        addRear(new Node<T>(val));
    }

    /**
     * @brief 덱의 후단 노드를 제거합니다.
     * 
     * @return Node<T>* 제거된 노드
     */
    Node<T>* deleteRear()
    {
        return this->remove(this->size()-1);
    }

    /**
     * @brief 덱의 후단 노드를 가져옵니다.
     * 
     * @return Node<T>* 후단 노드
     */
    Node<T>* getRear()
    {
        return this->getEntry(this->size()-1);
    }
};

int main(void)
{
    LinkedDeque<int> deq;

    for (int i = 1; i < 10; i++)
    {
        Node<int>* n = new Node<int>(i);
        if (i % 2)
            deq.addFront(n);
        else
            deq.addRear(n);
    }
    
    deq.display();

    delete deq.deleteFront();
    delete deq.deleteRear();
    delete deq.deleteFront();
    deq.display();

    return 0;
}