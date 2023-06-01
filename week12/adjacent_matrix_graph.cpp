#include <iostream>
#define MAX_VTXS 256

using namespace std;

class AdjMatGraph
{
protected:
    int size;                       // 정점의 개수
    char vertices[MAX_VTXS];        // 정점의 이름을 저장하는 배열
    int adj[MAX_VTXS][MAX_VTXS];    // 간선 정보를 저장하는 인접 행렬
public:

    AdjMatGraph()
    {
        reset();
    }

    ~AdjMatGraph() { }

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

    /**
     * @brief i번째 정점에서 j번째 정점으로 향하는 간선을 가져옵니다. 
     * 
     * @param i 출발하는 정점의 인덱스
     * @param j 도착하는 정점의 인덱스
     * @return int 간선의 값 (가중치 혹은 존재여부).
     */
    int getEdge(int i, int j)
    {
        return adj[i][j];
    }

    /**
     * @brief i번째 정점에서 j번째 정점으로 향하는 간선을 설정합니다.
     * 
     * @param i 출발하는 정점의 인덱스
     * @param j 도착하는 정점의 인덱스
     * @param val 간선의 값 (가중치 혹은 존재여부).
     */
    void setEdge(int i, int j, int val)
    {
        adj[i][j] = val;
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
     * @brief 그래프를 비어있는 상태로 초기화합니다.
     */
    void reset()
    {
        size = 0;
        for(int i = 0; i < MAX_VTXS; i++)
            for(int j = 0; j < MAX_VTXS; j++)
                setEdge(i, j, 0);
    }

    /**
     * @brief 정점을 추가합니다.
     * 
     * @param name 정점의 문자.
     */
    void insertVertext(char name)
    {
        if (isFull()) {
            cout << "Error: 그래프 정점 개수 초과" << endl;
        } else {
            vertices[size++] = name;
        }
    }

    /**
     * @brief 간선을 추가합니다.
     * 
     * @param u 정점의 인덱스.
     * @param v 정점의 인덱스.
     */
    void insertEdge(int u, int v)
    {
        // 무방향
        setEdge(u, v, 1);
        setEdge(v, u, 1);
    }

    /**
     * @brief 그래프를 출력합니다.
     */
    void display()
    {
        cout << "정점 개수: " << size << endl;
        cout << "  ";
        for (int i = 0; i < size; i++)
            cout << getVertex(i) << " ";
        cout << endl;
        for (int i = 0; i < size; i++) {
            cout << getVertex(i) << " ";
            for (int j = 0; j < size; j++) {
                cout << getEdge(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main(void)
{
    AdjMatGraph g;

    for (int i = 0; i < 4; i++)
        g.insertVertext('A' + i);
    
    g.insertEdge(0, 1);
    g.insertEdge(0, 3);
    g.insertEdge(1, 2);
    g.insertEdge(1, 3);
    g.insertEdge(2, 3);

    cout << "인접 행렬로 표현한 그래프" << endl;
    g.display();
}