//#include <iostream>
//
//using namespace std;
//
//int N, M;
//
//int visited[9];
//int graph[9];
//
//void dfs(int x, int len) {
//	if (len == M) {
//		for (int i = 0; i < M; i++) {
//			cout << graph[i] << ' ';
//		}
//		cout << "\n";
//		return;
//	}
//	for (int i = x; i <= N; i++) {
//		graph[len] = i;
//		dfs(i, len + 1);
//	}
//}
//
//int main() {
//
//	cin >> N >> M;
//
//	dfs(1, 0);
//
//}