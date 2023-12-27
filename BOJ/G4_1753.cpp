//#include <iostream>
//#include <vector>
//#include <queue>
//#define INF 10000000
//
//using namespace std;
//
//int V, E, start;
////int graph[20001][20001];
//int dist[20001];
//int visited[20001] = { 0, };
//vector<pair<int, int>> graph[20001];
//
////int find_next() {
////	int min_dist, min_index;
////	min_dist = INF;
////	min_index = -1;
////
////	for (int i = 1; i <= V; i++) {
////		if (visited[i] == 1) continue;		
////		if (dist[i] < min_dist) {
////			min_dist = dist[i];
////			min_index = i;
////		}		
////	}
////	if (min_dist == INF) return -1;
////	return min_index;
////}
//
////void update(int city) {
////	for (int i = 1; i <= V; i++) {
////		if (visited[i] == 1) continue;
////		if (dist[i] > dist[city] + graph[city][i])
////			dist[i] = dist[city] + graph[city][i];
////	}
////}
//
//int main() {
//	cin >> V >> E;
//	cin >> start;
//
//	int first, second, weight;
//	for (int i = 1; i <= E; i++) {
//		cin >> first >> second >> weight;
//		graph[first].push_back(make_pair(second, weight));
//	}
//
//	// start의 dist를 설정함
//	for (int i = 1; i <= V; i++) {	dist[i] = INF;	}
//
//	priority_queue<pair<int, int>> pq;
//	pq.push(make_pair(0, start));
//	dist[start] = 0;
//
//	while (!pq.empty()) {
//		int cost = -pq.top().first;
//		int current = pq.top().second;
//		pq.pop();
//
//		for (int i = 0; i < graph[current].size(); i++) {
//			int next = graph[current][i].first;
//			int nextcost = graph[current][i].second;
//
//			if (dist[next] > cost + nextcost) {
//				dist[next] = cost + nextcost;
//				pq.push(make_pair(-dist[next], next));
//			}
//		}
//	}
//
//	for (int i = 1; i <= V; i++) {
//		if (dist[i] == INF) cout << "INF" << "\n";
//		else cout << dist[i] << "\n";
//	}
//}