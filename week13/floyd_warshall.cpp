#include <iostream>
#include <vector>

using namespace std;

const int number = 4;
const int INF = 10000000;       // 초기 비용으로 쓸 무한대 값

vector<vector<int>> a {         // 각 노드 간의 비용 설정. 자신에게 가는 비용은 0, 아직 정해지지 않은 비용은 INF
    {0, 5, INF, 8},
    {7, 0, 9, INF},
    {2, INF, 0, 4},
    {INF, INF, 3, 0}
};

/**
 * @brief Floyd의 최단 경로 알고리즘
 */
void floyedWarshall()
{
    vector<vector<int>> d(number, Vector<int>(number));     // 결과를 저장할 2차원 벡터

    for (int i = 0; i < number; i++)                        // 결과 그래프를 초기화한다.
        for (int j = 0; j < number; j++)
            d[i][j] = a[i][j];
    
    for (int k = 0; k < number; k++)                        // k = 거쳐가는 노드
        for (int i = 0; i < number; i++)                    // i = 출발 노드
            for (int j = 0; j < number; j++)                // j = 도착 노드
                if (d[i][k] + d[k][j] < d[i][j])            // i에서 "k를 거쳐" k에서 j로 가는 비용이 i에서 j로 가는 비용보다 작으면, 최단 거리 갱신
                    d[i][j] = d[i][k] + d[k][j];


    for (int i = 0; i < number; i++)                        // 결과 출력
        for (int j = 0; j < number; j++)
            cout << d[i][j] << ' ';
        cout <<endl;
}

int main(void)
{
    floyedWarshall();
    return 0;
}