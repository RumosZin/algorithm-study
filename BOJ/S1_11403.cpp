//#include <iostream>
//#include <queue>
//#define INF 1000000
//
//using namespace std;
//
//int graph[101][101];
//int answer[101][101];
//
//int N;
//
//int main() {
//
//	cin >> N;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			cin >> graph[i][j];
//			if (graph[i][j] == 0) graph[i][j] = INF; // 1인 위치가 있는 경우 저장
//		}
//	}
//
//	// 플로이드-와샬로 구하는 방법
//	for (int k = 1; k <= N; k++) {
//		for (int i = 1; i <= N; i++) {
//			for (int j = 1; j <= N; j++) {
//				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
//			}
//		}
//	}
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			if (graph[i][j] == INF) cout << 0 << ' ';
//			else cout << 1 << ' ';
//		}
//		cout << "\n";
//	}
//}