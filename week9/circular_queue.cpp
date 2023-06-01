#include <iostream>
#define MAX_QUEUE_SIZE 100

using std::cerr;
using std::cout;
using std::endl;

inline void error(char* str)
{
    cerr << str << endl;
}

/**
 * @brief 원형 큐 클래스
 * 
 * @tparam T 큐가 가지는 데이터의 타입
 */
template <typename T>
class CircularQueue
{
    int front;
    int rear;
    T data[MAX_QUEUE_SIZE];

public:
    CircularQueue() : front(0), rear(0) {}

    ~CircularQueue() {}

    /**
     * @brief 큐가 비어있는지 확인합니다.
     * 
     * @return true front와 rear가 같으면, 큐가 비어있으므로 true.
     * @return false 그렇지 않으면, 큐에 원소가 있어 false.
     */
    bool isEmpty()
    {
        return front == rear;
    }

    /**
     * @brief 큐가 가득 찼는지 검사합니다.
     * 
     * @return true rear + 1이 front와 같으면 (mod 연산을 통해 전체 큐 순환), 큐가 가득 찼으므로 true.
     * @return false 그렇지 않으면, 아직 빈 공간이 있으므로 false.
     */
    bool isFull()
    {
        return (rear + 1) % MAX_QUEUE_SIZE == front;
    }

    /**
     * @brief 큐에 원소를 추가합니다.
     * 
     * @param val 큐에 추가할 원소
     */
    void enqueue(T val)
    {
        if (isFull())
            error("Error: 큐가 포화상태입니다.\n");
        else
        {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }

    /**
     * @brief 큐에서 원소를 제거합니다.
     * 
     * @return T 큐의 앞에 있는 원소
     */
    T dequeue()
    {
        if (isEmpty())
            error("Error: 큐가 공백 상태입니다.\n");
        else
        {
            front = (front + 1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }

    /**
     * @brief 큐에서 원소를 제거하지 않고 값만 가져옵니다.
     * 
     * @return T 큐의 앞에 있는 원소
     */
    T peek()
    {
        if (isEmpty())
            error("Error: 큐가 공백 상태입니다.\n");
        else
            return data[(front + 1) % MAX_QUEUE_SIZE];
    }

    /**
     * @brief 큐의 원소들을 확인합니다.
     */
    void display()
    {
        cout << "큐 내용 : ";
        int maxI = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
        for (int i = front + 1; i <= maxI; i++)
            cout << "[" << data[i % MAX_QUEUE_SIZE] << "] ";
        cout << endl;
    }
};

int main(void)
{
    CircularQueue<int> queue;

    for (int i = 1; i < 10; i++)
        queue.enqueue(i);
    queue.display();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.display();
    return 0;
}
