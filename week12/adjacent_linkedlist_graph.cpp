#include <iostream>
#include <fstream>
#define MAX_VTXS 256

using namespace std;

class Node
{
protected:
    int id;
    Node* link;
public:
    Node(int i, Node* l = nullptr) : id(i), link(l) { }
    
    ~Node()
    {
        if (link != nullptr)
            delete link;
    }

    int getId() {
        return id;
    }

    Node* getLink() {
        return link;
    }

    void setLink(Node* link) {
        this->link = link;
    }
};

class AdjListGraph
{
    int size;
    char vertices[MAX_VTXS];
    Node* adj[MAX_VTXS];
public:
    AdjListGraph(): size(0) {}
    ~AdjListGraph()
    {
        reset();
    }

    void reset()
    {
        for (int i = 0; i < size; i++)
            if (adj[i] != nullptr)
                delete adj[i];
        size = 0;
    }

    /**
     * @brief 그래프가 비어있는지 확인합니다.
     * 
     * @return true 그래프가 비어 있음. (정점이 없음)
     * @return false 그래프가 비어 있지 않음. (정점이 1개 이상 있음)
     */
    bool isEmpty()
    {
        return size == 0;
    }


    /**
     * @brief 그래프가 가득 차 있는지 확인합니다.
     * 
     * @return true 그래프가 가득 차 있음. (정점이 최대 개수만큼 있음)
     * @return false 그래프가 가득 차 있지 않음. (정점을 더 추가할 수 있음)
     */
    bool isFull()
    {
        return size == MAX_VTXS;
    }

    /**
     * @brief i번째 정점의 문자를 가져옵니다.
     * 
     * @param i 몇 번째 정점인지를 나타내는 인덱스 번호.
     * @return char 정점의 문자.
     */
    char getVertex(int i)
    {
        return vertices[i];
    }

    void insertVertex(char vertex)
    {
        if (isFull())
        {
            cout << "Error: 그래프 정점 개수 초과." << endl;
            return;
        }
        vertices[size] = vertex;
        adj[size++] = nullptr;
    }

    void insertEdge(int u, int v)
    {
        adj[u] = new Node(v, adj[u]);       // 기존 adj[u]에 있던 Node를 가리키는 새 Node를 만든 후 adj[u]에 저장.
        adj[v] = new Node(u, adj[v]);       // 기존 adj[v]에 있던 Node를 가리키는 새 Node를 만든 후 adj[v]에 저장.
    }

    void display()
    {
        cout << "그래프 정점 개수: " << size << endl;
        for (int i = 0; i < size; i++)
        {
            cout << getVertex(i) << " ";
            for (Node* n = adj[i]; n != nullptr; n = n->getLink())
                cout << " " << getVertex(n->getId());
            cout << endl;
        }
    }

    void load(const string& filename)
    {
        ifstream file(filename);

        int n;
        file >> n;                      // 정점의 전체 개수
        cout << "file: n: " << n << endl;
        for (int i = 0; i < n; i++)
        {
            char str[80];
            int val;
            file >> str;                // 정점의 이름
            cout << "file: str: " << str << endl;
            insertVertex(str[0]);       // 정점 삽입
            for (int j = 0; j < n; j++)
            {
                file >> val;            // 간선 정보
                cout << "file: val:" << val << endl;
                if (val != 0)           // 간선이 있으면
                    insertEdge(i, j);   // 간선 삽입
            }
        }
    }
};

int main(void)
{
    AdjListGraph g;

    for (int i = 0; i < 4; i++)
        g.insertVertex('A' + i);
    
    g.insertEdge(0, 1);
    g.insertEdge(0, 3);
    g.insertEdge(1, 2);
    g.insertEdge(1, 3);
    g.insertEdge(2, 3);

    cout << "인접 리스트로 표현한 그래프" << endl;
    g.display();
}
