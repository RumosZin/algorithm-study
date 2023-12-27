//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#define INF 10000000
//
//using namespace std;
//
//int N, M, X;
//int dist_xton[1001];
//int dist[2][1001];
//vector<pair<int, int>> graph[2][1001];
//
//void dijkstra(int k) {
//	dist[k][X] = 0; // 파티원은 제외
//
//	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
//	q.push({ 0, X });
//
//	while (!q.empty()) {
//		int distance = q.top().first;
//		int current = q.top().second;
//		q.pop();
//
//		if (distance > dist[k][current]) continue;
//
//		for (int i = 0; i < graph[k][current].size(); i++) {
//			int next = graph[k][current][i].second;
//			int next_distance = distance + graph[k][current][i].first;
//
//			if (next_distance < dist[k][next]) {
//				dist[k][next] = next_distance;
//				q.push({ next_distance, next });
//			}
//		}
//	}
//}
//
//int main() {
//	for (int i = 0; i <= N; i++) dist_xton[i] = INF;
//	cin >> N >> M >> X;
//
//	int start, end, time;
//	for (int i = 1; i <= M; i++) {
//		cin >> start >> end >> time;
//		graph[0][start].push_back({ time, end });
//		graph[1][end].push_back({ time, start });
//	}
//
//	for (int i = 0; i <= N; i++) {
//		dist[0][i] = INF;
//		dist[1][i] = INF;
//	}
//
//	dijkstra(0);
//	dijkstra(1);
//
//	int result = 0;
//
//	for (int i = 1; i <= N; i++) {
//		result = max(result, dist[0][i] + dist[1][i]);
//	}
//
//	cout << result << "\n";
//}