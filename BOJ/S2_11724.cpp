#include <iostream>
#include <vector>

using namespace std;

int N, M;
int answer = 0;
vector<int> graph[1001]; // 인접리스트
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;

    for(int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if(visited[next]) continue;
        dfs(next);
    }

    return;
}

int main() {
    // input
    cin >> N >> M;
    visited = vector<bool>(N + 1, false);
    
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 1; i <= N; i++) {
        if(visited[i]) continue;
        answer++;
        dfs(i);
    }

    cout << answer;

    return 0;
}