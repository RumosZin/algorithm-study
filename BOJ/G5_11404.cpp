//#include <iostream>
//#include <algorithm>
//#define INF 10000000
//
//using namespace std;
//
//int n, m;
//int graph[101][101];
//
//int main() {
//
//	cin >> n >> m;
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			graph[i][j] = INF;
//		}
//	}
//
//	int start;
//	int end;
//	int weight;
//	for (int i = 1; i <= m; i++) {
//		cin >> start >> end >> weight;
//
//		if (graph[start][end] < weight) { // 새로 입력 받은 값이 기존의 값보다 크면 패스
//			continue;
//		}
//		graph[start][end] = weight;
//	}
//
//	for (int k = 1; k <= n; k++) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
//			}
//		}
//	}
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if(graph[i][j] == INF || i == j) cout << 0 << " ";
//			else { cout << graph[i][j] << " "; }
//		}
//		cout << "\n";
//	}
//
//}