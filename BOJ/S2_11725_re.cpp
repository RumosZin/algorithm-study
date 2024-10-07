#include <iostream>
#include <vector>
#include <queue>

using namespace std; // 9:50

int N;
vector<int> graph[100001];
vector<int> visited;
int parent[100001];

int main() {
    // input
    cin >> N;
    visited.resize(N + 1);

    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    parent[1] = 0; // 1번이 루트이므로 부모가 0

    queue<pair<int, int>> q;
    q.push({0, 1}); // parent, child
    visited[1] = true;

    while(!q.empty()) {
        int p = q.front().first;
        int child = q.front().second;
        q.pop();

        parent[child] = p;

        for(int next : graph[child]) {
            if(visited[next]) continue;
            q.push({child, next});
            visited[next] = true;
        }
    }

    for(int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }

    return 0;

}