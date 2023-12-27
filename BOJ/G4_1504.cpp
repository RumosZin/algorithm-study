//#include <iostream>
//#include <algorithm>
//#define INF 10000000
//
//using namespace std;
//
//int N, E;
//
//int graph[801][801];
//int dist[801];
//int visited[801];
//
//int answer1, answer2;
//int first, second;
//int num1, num2, num3, num4, num5;
//
//int find_short() {
//	int min_dist = INF;
//	int min_index = -1;
//	for (int i = 1; i <= N; i++) {
//		if (visited[i] == 1) continue;
//		
//		if (min_dist > dist[i]) {
//			min_dist = dist[i];
//			min_index = i;
//		}
//	}
//	return min_index;
//}
//
//void update(int city) {
//	for (int i = 1; i <= N; i++) {
//		if (visited[i] == 1) continue;
//		if (dist[i] > dist[city] + graph[city][i]) 
//			dist[i] = dist[city] + graph[city][i];
//	}
//}
//
//void dijkstra(int city) {
//	for (int i = 1; i <= N; i++) {
//		dist[i] = graph[city][i];
//		visited[i] = 0;
//	}
//
//	/*for (int i = 1; i <= N; i++) {
//		cout << dist[i] << " uu ";
//	}*/
//	
//	visited[city] = 1;
//	dist[city] = 0;
//
//	for (int i = 1; i <= N; i++) {
//		int next = find_short();
//		visited[next] = 1; // 방문 처리
//		if (city == 1 && next == -1) { num1 = INF; num2 = INF; continue; }
//		if (city == N && next == -1) { num4 = INF; num5 = INF; continue; }
//		if (city == first && next == -1) { num3 = INF; continue; }
//
//		update(next);
//	}
//
//	if (city == 1) { num1 = dist[first]; num2 = dist[second]; }
//	if (city == N) { num4 = dist[first]; num5 = dist[second]; }
//	if (city == first) { num3 = dist[second]; }
//
//	/*for (int i = 1; i <= N; i++) {
//		cout << dist[i] << " dd ";
//	}*/
//}
//
//int main() {
//	cin >> N >> E;
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			graph[i][j] = INF;
//			if (i == j) graph[i][j] = 0;
//		}
//	}
//
//	int a, b, c;
//	for (int i = 1; i <= E; i++) {
//		cin >> a >> b >> c;
//		graph[a][b] = c;
//		graph[b][a] = c;
//	}
//
//	cin >> first >> second;
//	//cout << first << " hh " << second;
//
//	dijkstra(1);
//	dijkstra(first);
//	dijkstra(N);
//
//
//	answer1 = num1 + num3 + num5;
//	answer2 = num2 + num3 + num4;
//	int answer = min(answer1, answer2);
//
//	//cout << num1 << " ff " << num2 << " ff " << num3 << " ff " << num4 << " ff " << num5;
//	if (answer >= INF) cout << -1;
//	else cout << answer;
//
//}