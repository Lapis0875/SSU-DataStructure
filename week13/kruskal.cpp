#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_VERTICES 100

using namespace std;

/**
 * @brief 그래프의 간선을 나타내는 클래스. 간선의 두 노드와 가중치를 저장한다.
 */
class Edge
{
public:
    int node[2];
    int weight;

    /**
     * @brief 간선의 생성자. 노드와 가중치를 설정한다.
     * 
     * @param a 노드 1
     * @param b 노드 2
     * @param weight 가중치
     */
    Edge(int a, int b, int weight) : node{a, b}, weight(weight) {}

    /**
     * @brief sort를 지원하기 위해 비교 연산자를 오버로딩한다.
     * 
     * @param other 다른 간선 객체
     * @return true 
     * @return false 
     */
    bool operator<(Edge& other) {
        return this->weight < other.weight;
    }
};

/**
 * @brief 정점의 집합
 */
class VertexSets
{
private:
    int parent[MAX_VERTICES];   // 부모 정점의 id
    int size;                   // 집합의 개수

public:
    /**
     * @brief 정점의 집합 객체를 초기화.
     * 
     * @param nSets 집합의 개수
     */
    VertexSets(int nSets)
    {
        for (int i = 0; i < nSets; i++)
            parent[i] = -1;     // 모든 정점이 고유의 집합에 속한다.
    }

    /**
     * @brief 이 정점이 루트인지 판단.
     * 
     * @param i 
     * @return true 
     * @return false 
     */
    bool isRoot(int i)
    {
        return parent[i] < 0;
    }

    /**
     * @brief 인자로 정점이 속한 집합을 찾아 반환.
     * 
     * @param vertex 찾을 정점.
     * @return int 집합.
     */
    int findSet(int vertex)
    {
        int id = vertex;
        while(!isRoot(id))
            id = parent[id];
        return id;
    }

    /**
     * @brief 집합 1을 집합 2에 합친다.
     * 
     * @param s1 집합 1
     * @param s2 집합 2
     */
    void unionSets(int s1, int s2)
    {
        parent[s1] = s2;
        size--;
    }
};

/**
 * @brief 크루스칼 알고리즘 구현
 */
class Kruskal
{
public:
    VertexSets vs;
    vector<Edge> edges;

    /**
     * @brief 생성자
     * 
     * @param N 정점의 개수
     */
    Kruskal(int N): vs(N) {}

    /**
     * @brief 간선을 삽입한다.
     * 
     * @param nodeA 정점 1
     * @param nodeB 정점 2
     * @param weight 가중치
     */
    void insertEdge(int nodeA, int nodeB, int weight)
    {
        edges.push_back(Edge(nodeA, nodeB, weight));
    }

    /**
     * @brief 크루스칼 알고리즘을 실행한다.
     */
    void execute()
    {
        sort(edges.begin(), edges.end());       // 간선을 가중치 기준으로 정렬한다.

        int totalWeight = 0;
        for (Edge edge: edges)                  // 모든 간선에 대해
        {
            int set1 = vs.findSet(edge.node[0]);
            int set2 = vs.findSet(edge.node[1]);

            if (set1 != set2)                   // 두 노드가 다른 집합에 속해 있다면
            {
                totalWeight += edge.weight;     // 가중치 더하기
                vs.unionSets(set1, set2);       // 두 집합 합치기

                cout << "Added edge " << edge.node[0] << " - " << edge.node[1] << " with weight " << edge.weight << endl;
            }
        }

        cout << "Total weight: " << totalWeight << endl;    // 총 가중치 출력
    }
};

int main(void)
{
    Kruskal kruskal(7);
    kruskal.insertEdge(0, 1, 9);
    kruskal.insertEdge(0, 2, 10);
    kruskal.insertEdge(1, 3, 10);
    kruskal.insertEdge(1, 4, 5);
    kruskal.insertEdge(2, 4, 7);
    kruskal.insertEdge(2, 5, 2);
    kruskal.insertEdge(3, 6, 4);
    kruskal.insertEdge(4, 6, 7);
    kruskal.insertEdge(5, 6, 6);

    kruskal.execute();
    return 0;
}