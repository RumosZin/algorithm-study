//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N, M;
//int parent[1001];
//vector<pair<int, pair<int, int>>> v;
//int answer;
//
//int findParent(int x) {
//	if (parent[x] == x) return x;
//	else return parent[x] = findParent(parent[x]);
//}
//
//void Union(int x, int y) {
//	x = findParent(x);
//	y = findParent(y);
//	if (x != y) parent[y] = x;
//}
//
//bool sameParent(int x, int y) {
//	x = findParent(x);
//	y = findParent(y);
//
//	if (x == y) return true;
//	else return false;
//}
//
//int main() {
//	cin >> N >> M;
//	int a, b, cost;
//	for (int i = 0; i < M; i++) {
//		cin >> a >> b >> cost;
//		v.push_back({ cost, {a, b} });
//	}
//
//	sort(v.begin(), v.end());
//	
//	for (int i = 0; i < N; i++) parent[i] = i;
//
//	for (int i = 0; i < M; i++) {
//		if (sameParent(v[i].second.first, v[i].second.second) == false) {
//			Union(v[i].second.first, v[i].second.second);
//			answer += v[i].first;
//		}
//	}
//	cout << answer;
//}