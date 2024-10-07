#include <iostream>
#include <vector>
#include <queue>

using namespace std; // 8:59

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> friends[501];
    vector<bool> visited(N + 1);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        friends[u].push_back(v);
        friends[v].push_back(u);
    }

    // 상근이 친구들 확인
    int answer = 0;
    queue<int> q;
    visited[1] = true;

    if(friends[1].size() == 0) {
        cout << 0;
        return 0;
    }

    for(int i = 0; i < friends[1].size(); i++) {
        q.push(friends[1][i]); // 상근이 친구
        visited[friends[1][i]] = true;
        answer++;
    }

    // 상근이 친구의 친구
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < friends[cur].size(); i++) {
            if(!visited[friends[cur][i]]) {
                visited[friends[cur][i]] = true;
                answer++;
            }
        }
    }

    cout << answer;

    return 0;
}