#include <iostream>
#include <vector>
#include <queue>

#define MAX_VERTICES 100

using namespace std;

/**
 * @brief 그래프의 간선을 나타내는 클래스. 간선의 두 노드와 가중치를 저장한다.
 */
class Edge
{
public:
    int node;
    int weight;

    /**
     * @brief 단방향 간선의 생성자. 노드와 가중치를 설정한다.
     * 
     * @param a 노드
     * @param weight 가중치
     */
    Edge(int a, int weight) : node(a), weight(weight) {}

    /**
     * @brief sort를 지원하기 위해 비교 연산자를 오버로딩한다.
     * 
     * @param other 다른 간선 객체
     * @return true 
     * @return false 
     */
    bool operator<(const Edge& other) const {
        return this->weight < other.weight;
    }
};

/**
 * @brief 프림 알고리즘
 */
class Prim
{
public:
    int num_vertex;                         // 정점 개수
    vector<Edge> graph[MAX_VERTICES];       // 간선의 집합

    /**
     * @brief 생성자
     * 
     * @param num_vertex 정점의 개수
     */
    Prim(int num_vertex) : num_vertex(num_vertex) {}

    /**
     * @brief 간선을 추가한다.
     * 
     * @param nodeA 노드 1
     * @param nodeB 노드 2
     * @param weight 가중치
     */
    void addEdge(int nodeA, int nodeB, int weight)
    {
        // 단방향 간선을 각 정점에 서로 추가한다.
        graph[nodeA].push_back(Edge(nodeB, weight));
        graph[nodeB].push_back(Edge(nodeA, weight));
    }

    /**
     * @brief 프림 알고리즘을 수행한다.
     * 
     * @param start 시작 정점
     */
    void execute(int start)
    {
        vector<bool> selected(num_vertex, false);       // 정점의 선택 여부를 나타내는 벡터.
        priority_queue<Edge> pq;                        // 우선순위 큐를 사용해 간선을 저장하고 최소 가중치 간선을 선택.
        pq.push(Edge(start, 0));                        // 시작 정점을 큐에 삽입.

        int totalWeight = 0;                            // 가중치의 합을 저장하는 변수.
        while (!pq.empty())
        {
            Edge cur = pq.top();
            pq.pop();

            if (selected[cur.node]) continue;               // 이미 선택된 정점은 스킵.

            selected[cur.node] = true;                      // 정점을 선택되었다고 표시한다.
            totalWeight += cur.weight;                      // 현재 정점의 가중치를 비용에 추가.

            for (Edge next: graph[cur.node])                // 현재 정점과 연결된 간선들에 대해
                if (!selected[next.node])                   // 해당 간선의 정점이 선택되지 않았다면
                    pq.push(next);                          // 우선순위 큐에 삽입.
        }

        cout << "Total weight: " << totalWeight << endl;    // 최소 비용 출력.
    }
};

int main(void)
{
    Prim prim(7);
    prim.addEdge(0, 1, 9);
    prim.addEdge(0, 2, 10);
    prim.addEdge(1, 3, 10);
    prim.addEdge(1, 4, 5);
    prim.addEdge(2, 4, 7);
    prim.addEdge(2, 5, 2);
    prim.addEdge(3, 6, 4);
    prim.addEdge(4, 6, 7);
    prim.addEdge(5, 6, 6);

    prim.execute(0);

    return 0;
}