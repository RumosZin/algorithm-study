//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> graph[100001];
//int visited[100001];
//int parent[100001];
//int N;
//
//void dfs(int input) {
//	if (visited[input] == 1) return;
//	visited[input] = 1;
//
//	//if (graph[input].size() == 1) return;
//	for (int i = 0; i <= graph[input].size() - 1; i++) {
//		if (visited[graph[input][i]] == 1) continue;
//		parent[graph[input][i]] = input;
//		dfs(graph[input][i]);
//	}
//	
//}
//
//int main() {
//	cin >> N;
//	int first, second;
//	for (int i = 1; i <= N-1; i++) {
//		cin >> first >> second;
//		graph[first].push_back(second);
//		graph[second].push_back(first);
//	}
//
//	dfs(1);
//
//	for (int i = 2; i <= N; i++) {
//		cout << parent[i] << "\n";
//	}
//}