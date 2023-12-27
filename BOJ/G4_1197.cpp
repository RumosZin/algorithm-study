//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int parent[10001];
//int V, E;
//vector<pair<int, pair<int, int>>> graph;
//int answer;
//
//// 인풋 노드의 부모를 찾는 find 함수
//int findParent(int x) {
//	if (parent[x] == x) return x;
//	else return parent[x] = findParent(parent[x]);
//}
//
//// 서로 다른 부모일 경우, 두 개의 노드를 연결해주는 union 함수
//void Union(int x, int y) {
//	x = findParent(x);
//	y = findParent(y);
//	if (x != y) {
//		parent[y] = x;
//	}
//}
//
//// 서로 같은 부모를 갖는지 판단하는 함수 
//bool sameParent(int x, int y) {
//	x = findParent(x);
//	y = findParent(y);
//
//	if (x == y) return true;
//	else return false;
//}
//
//int main() {
//	cin >> V >> E;
//	answer = 0;
//	int a, b, cost;
//	for (int i = 0; i < E; i++) {
//		cin >> a >> b >> cost;
//		graph.push_back({ cost, {a, b} });
//	}
//
//	sort(graph.begin(), graph.end());
//
//	for (int i = 1; i <= V; i++) {
//		parent[i] = i; // 초기 시작 
//	}
//
//	for (int i = 0; i < E; i++) {
//		if (sameParent(graph[i].second.first, graph[i].second.second) == false) {
//			Union(graph[i].second.first, graph[i].second.second);
//			answer += graph[i].first;
//		}
//	}
//	cout << answer;
//}