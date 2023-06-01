#include <iostream>
#include <vector>

using namespace std;

#define INF 1000000000              // 초기 비용을 "무한대"로 설정.

int number = 6;                     // 총 노드의 수
int start = 1;                      // 시작 노드 번호
bool visited[6];                    // 방문한 노드를 표시하는 배열
int dist[6];                        // 최단 거리를 저장하는 배열
vector<pair<int, int>> a[7];        // pair<index, weight>, 각 노드와 연결된 다른 노드와, 그 거리를 저장하는 벡터의 배열

/**
 * @brief 다익스트라 알고리즘
 * 
 * @param start 시작 노드의 번호
 */
void dijkstra(int start)
{
    dist[start] = 0;                        // 시작 노드의 최단 거리는 0으로 초기화
    for  (int i = 0; i < number; i++)   
    {
        int current = -1;                   // 현재 노드를 저장하는 변수
        int minDist = INF;                  // 최단 거리를 저장하는 변수

        for (int j = 1; j <= number; j++)           // 최단 거리의 노드를 찾는다
        {
            if (!visited[j] && dist[j] < minDist)   // 방문하지 않았던 노드 중, 이전까지의 최단 거리보다 더 짧은 거리의 노드가 있다면
            {
                // 변수 값 갱신
                minDist = dist[j];
                current = j;
            }
        }
        visited[current] = true;            // 현재 노드를 방문했다고 표시

        for (int j = 0; j < a[current].size(); j++)         // 현재 노드와 연결된 다른 노드들의 거리 갱신
        {
            int near = a[current][j].first;                 // 연결된 노드
            int nearDist = a[current][j].second;            // 연결된 노드와의 거리

            if (dist[near] > dist[current] + nearDist)      // 기존에 저장된 거리보다 더 짧은 거리라면 갱신
                dist[near] = dist[current] + nearDist;
        }       
    }
}

int main(void)
{
    for (int i = 1; i <= number; i++)
        dist[i] = INF;      // 모든 노드까지의 최단 거리를 INF로 설정한다.
    
    // 각 노드와 연결된 노드와 그 거리를 저장한다.
    a[1].push_back(make_pair(2, 2));
    a[1].push_back(make_pair(3, 5));
    a[1].push_back(make_pair(4, 1));
    a[2].push_back(make_pair(1, 2));
    a[2].push_back(make_pair(3, 3));
    a[2].push_back(make_pair(4, 2));
    a[3].push_back(make_pair(1, 5));
    a[3].push_back(make_pair(2, 3));
    a[3].push_back(make_pair(4, 3));
    a[3].push_back(make_pair(5, 1));
    a[3].push_back(make_pair(6, 5));
    a[4].push_back(make_pair(1, 1));
    a[4].push_back(make_pair(2, 2));
    a[4].push_back(make_pair(3, 3));
    a[4].push_back(make_pair(5, 1));
    a[5].push_back(make_pair(3, 1));
    a[5].push_back(make_pair(4, 1));
    a[5].push_back(make_pair(6, 2));
    a[6].push_back(make_pair(3, 5));
    a[6].push_back(make_pair(5, 2));

    dijkstra(start);

    // 결과 출력
    for (int i = 1; i <= number; i++)
        if (dist[i] == INF)
            cout << "INF" << " ";
        else
            cout << dist[i] << " ";
    cout << endl;

    return 0;
}
