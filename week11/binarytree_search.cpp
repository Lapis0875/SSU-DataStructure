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
    BinaryNode<T>* root;        // 이진 트리의 루트 노드

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
                cout << "[" << node->getData() << "] ";
                queue.enqueue(node->getLeft());
                queue.enqueue(node->getRight());
            }
        }
        cout << endl;
    }
};

/**
 * @brief 이진 탐색 트리 클래스
 * 
 * @tparam T 이진 트리의 노드가 가질 데이터의 타입
 */
template <typename T>
class BinarySearchTree: public BinaryTree<T>
{
public:
    /**
     * @brief 주어진 키 값을 갖는 노드를 탐색합니다.
     * 
     * @param key 키 값
     * @return BinaryNode<T>* 해당 키 값을 가지는 노드의 주소. 없으면 nullptr.
     */
    BinaryNode<T>* search(T key)
    {
        BinaryNode<T>* node = search(this->root, key);

        if (node != nullptr)
            printf("탐색성공: 키 값이  %d인 노드 = 0x%p\n", key, node);
        else
            printf("탐색실패: 키 값이 %d인 노드 없음.\n", key);
        return node;
    }

    /**
     * @brief 주어진 키 값을 갖는 노드를 탐색합니다.
     * 
     * @param node 탐색을 시작할 부모 노드
     * @param key 키 값
     * @return BinaryNode<T>* 해당 키 값을 가지는 노드의 주소.
     */
    BinaryNode<T>* search(BinaryNode<T>* node, T key)
    {
        if (node == nullptr)
            return nullptr;
        
        T nodeData = node->getData();
        
        if (key == nodeData)
            return node;
        else if (key < nodeData)
            return search(node->getLeft(), key);
        else
            return search(node->getRight(), key);
    }

    /**
     * @brief 트리에 노드를 삽입합니다.
     * 
     * @param node 삽입할 노드의 주소.
     */
    void insert(BinaryNode<T>* node)
    {
        if (node == nullptr)
            return;
        if (this->isEmpty())
            this->root = node;
        else
            insert(this->root, node);
    }

    /**
     * @brief 트리에 노드를 삽입합니다.
     * 
     * @param r 삽입할 노드의 부모 노드.
     * @param n 삽입할 노드.
     */
    void insert(BinaryNode<T>* r, BinaryNode<T>* n)
    {
        T rData = r->getData();
        T nData = n->getData();

        if (nData == rData)
            return;
        else if (nData < rData)
        {
            if (r->getLeft() == nullptr)
                r->setLeft(n);
            else
                insert(r->getLeft(), n);
        }
        else
        {
            if(r->getRight() == nullptr)
                r->setRight(n);
            else
                insert(r->getRight(), n);
        }
    }

    /**
     * @brief 트리에서 주어진 데이터를 가지는 노드를 삭제합니다.
     * 
     * @param data 삭제할 노드의 키.
     */
    void remove(T data)
    {
        if (this->isEmpty())
            return;
        
        BinaryNode<T>* parent = nullptr;
        BinaryNode<T>* cur = this->root;

        while(cur != nullptr && cur->getData() != data)
        {
            parent = cur;
            cur = (data < cur->getData()
                    ? cur->getLeft()
                    : cur->getRight());
        }

        if (cur == nullptr)
        {
            printf("삭제 실패: %d는 트리에 존재하지 않는 키입니다.\n", data);
            return;
        }
        else
            remove(parent, cur);
    }

    /**
     * @brief 트리에서 노드를 삭제합니다.
     * 
     * @param parent 삭제할 노드의 부모 노드의 주소.
     * @param node 삭제할 노드의 주소.
     */
    void remove(BinaryNode<T>* parent, BinaryNode<T>* node)
    {
        // case1 : 단말 노드일 때
        if (node->isLeaf())
        {
            if (parent == nullptr)
                this->root = nullptr;
            else
            {
                if (parent->getLeft() == node)
                    parent->setLeft(nullptr);
                else
                    parent->setRight(nullptr);
            }
        }
        // case 2 : 자식 노드가 1개
        else if (node->getLeft() == nullptr || node->getRight() == nullptr)
        {
            BinaryNode<T>* child = (node->getLeft() != nullptr
                                    ? node->getLeft()
                                    : node->getRight());
            if (node == this->root)
                this->root = child;
            else
            {
                if (parent->getLeft() == node)
                    parent->setLeft(child);
                else
                    parent->setRight(child);
            }
        }
        // case 3 : 자식 노드가 2개
        else
        {
            BinaryNode<T>* succp = node;
            BinaryNode<T>* succ = node->getRight();

            while (succ->getLeft() != nullptr)
            {
                succp = succ;
                succ = succ->getLeft();
            }

            if (succp->getLeft() == succ)
                succp->setLeft(succ->getRight());
            else
                succp->setRight(succ->getRight());
            
            node->setData(succ->getData());
            node = succ;
        }
        delete node;
    }
};

int main(void)
{
    BinarySearchTree<int> tree;

    // 트리에 노드 추가
    tree.insert(new BinaryNode<int>(35));
    tree.insert(new BinaryNode<int>(18));
    tree.insert(new BinaryNode<int>(7));
    tree.insert(new BinaryNode<int>(26));
    tree.insert(new BinaryNode<int>(12));
    tree.insert(new BinaryNode<int>(3));
    tree.insert(new BinaryNode<int>(68));
    tree.insert(new BinaryNode<int>(22));
    tree.insert(new BinaryNode<int>(30));
    tree.insert(new BinaryNode<int>(99));

    // 트리 순회
    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelorder();

    // 트리 탐색
    tree.search(26);
    tree.search(25);

    printf("삭제 case 1: Node(3) 삭제\n");
    tree.remove(3);
    tree.levelorder();

    printf("삭제 case 2: Node(68) 삭제\n");
    tree.remove(68);
    tree.levelorder();

    printf("삭제 case 3: Node(18) 삭제\n");
    tree.remove(18);
    tree.levelorder();

    printf("삭제 case 2: Node(35) 삭제 (루트 노드 삭제)\n");
    tree.remove(35);
    tree.levelorder();

    return 0;
}