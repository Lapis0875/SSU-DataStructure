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
    Node<T>* link;
    T data;
public:
    Node(T val) : data(val), link(nullptr) {}
    
    /**
     * @brief 이 노드가 가리키는 노드의 주소를 가져옵니다.
     * 
     * @return Node<T>* 이 노드가 가리키는 노드의 주소.
     */
    Node<T>* getLink()
    {
        return link;
    }

    /**
     * @brief 이 노드가 인자로 받은 노드를 가리키게 합니다.
     * 
     * @param next 가리킬 노드의 주소.
     */
    void setLink(Node<T>* next)
    {
        link = next;
    }

    /**
     * @brief 이 노드의 정보를 콘솔에 출력함.
     */
    void display()
    {
        cout << " <" << data << ">";
    }
};

/**
 * @brief 연결 리스트를 이용한 큐 클래스
 * 
 * @tparam T 큐가 가지는 데이터의 타입
 */
template <typename T>
class LinkedQueue
{
    Node<T>* front;
    Node<T>* rear;

public:
    LinkedQueue() : front(nullptr), rear(nullptr) {}
    ~LinkedQueue()
    {
        while(!isEmpty())
            delete dequeue();
    }

    /**
     * @brief 큐가 비었는지 검사한다.
     * 
     * @return true front가 nullptr이면 큐가 비어있음.
     * @return false 그렇지 않으면 큐는 원소를 가짐.
     */
    bool isEmpty()
    {
        return front == nullptr;
    }

    /**
     * @brief 큐에 새 원소를 추가한다.
     * 
     * @param node 새 노드의 주소.
     */
    void enqueue(Node<T>* node)
    {
        if (isEmpty())
            front = rear = node;
        else
        {
            rear->setLink(node);
            rear = node;
        }
    }

    /**
     * @brief 큐에 새 원소를 추가한다.
     * 
     * @param val 새 노드가 가질 값.
     */
    void enqueue(T val)
    {
        enqueue(new Node<T>(val));
    }

    /**
     * @brief 큐에서 원소를 제거하고 가져온다.
     * 
     * @return Node<T>* 큐에서 제거한 노드의 주소.
     */
    Node<T>* dequeue()
    {
        if (isEmpty())
            return nullptr;
            
        Node<T>* tmp = front;
        front = front->getLink();

        if (front == nullptr)   // 만약 노드 하나 제거 후 link가 nullptr이면
            rear == nullptr;    // 큐가 비었다는 뜻이므로 rear도 nullptr로 설정
        
        return tmp;
    }


    /**
     * @brief 큐에서 원소를 제거하지 않고 가져온다.
     * 
     * @return Node<T>* 큐에서 제거한 노드의 주소.
     */
    Node<T>* peek()
    {
        return front;
    }


    /**
     * @brief 큐의 원소들을 콘솔에 출력한다.
     */
    void display()
    {
        cout << "[큐 내용] : ";
        for (Node<T>* p = front; p != nullptr; p = p->getLink())
            p->display();
        cout << endl;
    }
};

int main(void)
{
    LinkedQueue<int> queue;

    for (int i = 1; i < 10; i++)
        queue.enqueue(i);       // queue.enqueue(new Node<int>(i)) 를 내부적으로 호출하는 오버로딩.
    
    queue.display();

    delete queue.dequeue();
    delete queue.dequeue();
    delete queue.dequeue();
    queue.display();

    return 0;
}