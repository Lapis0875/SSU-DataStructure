#include <iostream>
#define MAX_QUEUE_SIZE 100

using std::cerr;
using std::cout;
using std::endl;

inline void error(const char* str)
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
            error("Error: 큐가 공백 상태입니다.\n");
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
        {
            error("Error: 큐가 포화상태입니다.\n");
            return nullptr;
        }
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

/**
 * @brief 이진 트리의 노드 클래스
 * 
 * @tparam T 노드의 데이터 타입
 */
template <typename T>
class BinaryNode
{
protected:
    T data;                 // 이 노드의 데이터
    BinaryNode<T>* left;    // 왼쪽 자식 노드의 포인터
    BinaryNode<T>* right;   // 오른쪽 자식 노드의 포인터
public:
    BinaryNode(T val = 0, BinaryNode<T>* left = nullptr, BinaryNode<T>* right = nullptr) : data(val), left(left), right(right) {}
    ~BinaryNode() {}

    /**
     * @brief 이 노드의 데이터를 설정합니다.
     * 
     * @param val 설정할 데이터.
     */
    void setData(T val)
    {
        data = val;
    }

    /**
     * @brief 노드의 데이터를 반환합니다.
     * 
     * @return T 노드의 데이터.
     */
    T getData()
    {
        return data;
    }

    /**
     * @brief 이 노드의 왼쪽 자식 노드를 설정합니다.
     * 
     * @param left 노드의 주소.
     */
    void setLeft(BinaryNode<T>* left)
    {
        this->left = left;
    }

    /**
     * @brief 이 노드의 왼쪽 자식 노드의 주소를 반환합니다.
     * 
     * @return BinaryNode<T>* 왼쪽 자식 노드의 주소.
     */
    BinaryNode<T>* getLeft()
    {
        return left;
    }

    /**
     * @brief 이 노드의 오른쪽 자식 노드를 설정합니다.
     * 
     * @param right 노드의 주소.
     */
    void setRight(BinaryNode<T>* right)
    {
        this->right = right;
    }

    /**
     * @brief 이 노드의 오른쪽 자식 노드의 주소를 반환합니다.
     * 
     * @return BinaryNode<T>* 오른쪽 자식 노드의 주소.
     */
    BinaryNode<T>* getRight()
    {
        return right;
    }
    
    /**
     * @brief 이 노드가 단말 노드인지 검사합니다.
     * 
     * @return true 단말 노드입니다. (자식 노드 X)
     * @return false 단말 노드가 아닙니다. (자식 노드 O)
     */
    bool isLeaf()
    {
        return left == nullptr && right == nullptr;
    }
};

/**
 * @brief 이진 트리 클래스
 * 
 * @tparam T 이진 트리의 노드가 가질 데이터의 타입
 */
template <typename T>
class BinaryTree
{
private:
    BinaryNode<T>* root;        // 이진 트리의 루트 노드

    /**
     * @brief 주어진 노드의 정보를 출력합니다.
     * 
     * @param node 출력할 노드
     * @param depth 현재 노드의 깊이
     */
    void display(BinaryNode<T>* node, int depth)
    {
        if (node == nullptr)
            return;
        
        for (int i = 0; i < depth; i++)
            cout << "  ";
        // cout << "- " << static_cast<char>(node->getData()) << endl;
        cout << "- " << node->getData() << endl;

        display(node->getLeft(), depth + 1);
        display(node->getRight(), depth + 1);
    }

    // 순회 알고리즘
    /**
     * @brief 주어진 노드를 전위 순회합니다.
     * 
     * @param node 순회할 서브트리의 최상위 노드.
     */
    void preorder(BinaryNode<T>* node)
    {
        if (node == nullptr)    // 현재 노드가 nullptr이면 재귀 종료
            return;
        
        cout << "[" << node->getData() << "] ";     // 현재 노드를 처음으로 조회
        preorder(node->getLeft());                  // 왼쪽 서브트리를 다음으로 순회
        preorder(node->getRight());                 // 오른쪽 서브트리를 마지막으로 순회
    }

    /**
     * @brief 주어진 노드를 중위 순회합니다.
     * 
     * @param node 순회할 서브트리의 최상위 노드.
     */
    void inorder(BinaryNode<T>* node)
    {
        if (node == nullptr)    // 현재 노드가 nullptr이면 재귀 종료
            return;
        
        inorder(node->getLeft());                   // 왼쪽 서브트리를 처음으로 순회
        cout << "[" << node->getData() << "] ";     // 현재 노드를 다음으로 조회
        inorder(node->getRight());                  // 오른쪽 서브트리를 마지막으로 순회
    }

    /**
     * @brief 주어진 노드를 후위 순회합니다.
     * 
     * @param node 순회할 서브트리의 최상위 노드.
     */
    void postorder(BinaryNode<T>* node)
    {
        if (node == nullptr)    // 현재 노드가 nullptr이면 재귀 종료
            return;
        
        postorder(node->getLeft());                 // 왼쪽 서브트리를 처음으로 순회
        postorder(node->getRight());                // 오른쪽 서브트리를 다음으로 순회
        cout << "[" << node->getData() << "] ";     // 현재 노드를 마지막으로 조회
    }

public:
    BinaryTree(): root(nullptr) {}
    ~BinaryTree()
    {

    }

    /**
     * @brief 루트 노드를 설정합니다.
     * 
     * @param node 노드의 주소.
     */
    void setRoot(BinaryNode<T>* node)
    {
        root = node;
    }

    /**
     * @brief 루트 노드의 주소를 반환합니다.
     * 
     * @return BinaryNode<T>* 루트 노드의 주소.
     */
    BinaryNode<T>* getRoot()
    {
        return root;
    }

    /**
     * @brief 트리가 비어있는지 검사합니다.
     * 
     * @return true 루트 노드가 nullptr
     * @return false 루트 노드가 존재함.
     */
    bool isEmpty()
    {
        return root == nullptr;
    }

    /**
     * @brief 이진 트리의 정보를 출력합니다.
     */
    void display()
    {
        cout << "Binary tree : " << endl;
        if (isEmpty())
            cout << "(tree is empty)" << endl;
        else
            display(root, 0);
    }

    // 순회 알고리즘

    /**
     * @brief 트리를 전위순회 방식으로 탐색합니다.
     */
    void preorder()
    {
        cout << "preorder : ";
        preorder(root);
        cout << endl;
    }

    /**
     * @brief 트리를 중위순회 방식으로 탐색합니다.
     */
    void inorder()
    {
        cout << "inorder : ";
        inorder(root);
        cout << endl;
    }

    /**
     * @brief 트리를 후위순회 방식으로 탐색합니다.
     */
    void postorder()
    {
        cout << "postorder : ";
        postorder(root);
        cout << endl;
    }

    /**
     * @brief 트리를 레벨순회 방식으로 탐색합니다.
     */
    void levelorder()
    {
        cout << "levelorder : ";
        if (isEmpty())
            return;
        
        CircularQueue<BinaryNode<T>*> queue;
        queue.enqueue(root);

        while(!queue.isEmpty())
        {
            BinaryNode<T>* node = queue.dequeue();
            if (node != nullptr)
            {
                cout << "[" << static_cast<char>(node->getData()) << "] ";
                queue.enqueue(node->getLeft());
                queue.enqueue(node->getRight());
            }
        }
        cout << endl;
    }
};

int main(void)
{
    BinaryTree<char> tree;

    /*
    - A
        - B
            - D
            - E
        - C
            - F
    */
    BinaryNode<char>* d = new BinaryNode<char>('D', nullptr, nullptr);
    BinaryNode<char>* e = new BinaryNode<char>('E', nullptr, nullptr);
    BinaryNode<char>* b = new BinaryNode<char>('B', d, e);
    BinaryNode<char>* f = new BinaryNode<char>('F', nullptr, nullptr);
    BinaryNode<char>* c = new BinaryNode<char>('C', f, nullptr);
    BinaryNode<char>* a = new BinaryNode<char>('A', b, c);

    tree.setRoot(a);
    tree.display();

    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelorder();

    return 0;
}