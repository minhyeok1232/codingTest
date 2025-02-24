#include <iostream>
#include <queue>
using namespace std;
int N, M, V;
int map[1001][1001];
bool visited[1001] = { false };

queue<int> q;

// 1. N, M, V를 외부에 선언하는 이유는 해당 변수가 DFS, BFS 함수에 들어갈 것
// 2. map과 visited도 마찬가지이며,
// 3. map[1][2] 간선과 map[2][1] 간선은 같으며 미방문 시 1, 방문 시 0으로 처리

// DFS
void DFS(int V) {
    // 1. V에서 시작하므로, 방문한 부분은 true로 처리
    visited[V] = true;

    cout << V << " ";

    // 2. i는 1부터 가야함 map[a][b]가 따라가는 것이기에
    // 2-1) visited[i] = false (방문이 되어있으면 절대 안됨)
    // 2-2) map[V][i] = 1 (V에서 시작된 점에서 정점이 연결되어 있어야 한다)
    for (int i = 0; i <= N; i++) {
        if (!visited[i] && map[V][i] == 1)
            DFS(i);
    }
}

// BFS
void BFS(int V) {
    q.push(V);
    visited[V] = true;
    cout << V << " ";
    while (!q.empty()) {
        V = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if (!visited[i] && map[V][i] == 1) {
                q.push(i);
                visited[i] = true;
                cout << i << " ";
            }
        }
    }
}



int main() {
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        int a, b;   // a와 b는 간선이며 map에 들어갈 것.
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }


    // 1. DFS 함수
    DFS(V);

    for (int i = 1; i <= N; i++) {
        visited[i] = false;
    }
    cout << '\n';

    // 2. BFS 함수
    BFS(V);
    cout << '\n';
}