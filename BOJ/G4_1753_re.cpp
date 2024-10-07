#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321

using namespace std; // 9:24

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // input
    int V, E, start;
    cin >> V >> E >> start;
    vector<pair<int, int>> adj[20001];

    for(int i = 0; i < E; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({cost, v}); // 비용, 정점
    }

    // start 부터 시작
    vector<int> dist(V + 1, INF);

    dist[start] = 0; // 시작점 자기 자신은 0으로 설정
    // start의 인접 리스트 확인
    priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> pq; // 비용, 정점 내림차순

    pq.push({dist[start], start}); // 비용, 정점
    while(!pq.empty()) {
        int cost = pq.top().first; // 비용
        int node = pq.top().second; // 정점front가 아니고 top이다
        pq.pop();

        // 거리가 현재 dist보다 작으면 스킵해야한다
        if(dist[node] != cost) continue;

        for(int i = 0; i < adj[node].size(); i++) {
            // node를 거치는 것이 작아지는지 확인 필요
            int ncost = adj[node][i].first;
            int next = adj[node][i].second;
            if(dist[next] > dist[node] + ncost) {
                dist[next] = dist[node] + ncost;
                pq.push({dist[next], next});
            }
        }

    }

    for(int i = 1; i <= V; i++) {
        if(dist[i] == INF) cout << "INF" << "\n";
        else cout << dist[i] << "\n";
    }

    return 0;


}