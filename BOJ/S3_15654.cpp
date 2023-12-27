//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N, M;
//
//int visited[9];
//int graph[9];
//vector<int> input;
//
//void dfs(int x, int len) {
//	if (len == M) {
//		for (int i = 0; i < M; i++) {
//			cout << graph[i] << ' ';
//		}
//		cout << "\n";
//		return;
//	}
//	for (int i = 0; i < input.size(); i++) {
//		if (visited[i] == 0) {
//			graph[len] = input[i];
//			visited[i] = 1;
//			dfs(x, len + 1);
//			visited[i] = 0;
//		}
//	}
//}
//
//int main() {
//
//	cin >> N >> M;
//	int num;
//	for (int i = 0; i < N; i++) {
//		cin >> num;
//		input.push_back(num);
//	}
//	sort(input.begin(), input.end()); // 오름차순 정렬
//
//	dfs(input[0], 0);
//
//}