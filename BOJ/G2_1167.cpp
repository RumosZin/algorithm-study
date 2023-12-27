//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int V;
//vector<pair<int, int>> graph[100001];
//int visited[100001] = { 0, };
//int max_dist;
//int max_node;
//
//void dfs(int input, int dist) { // 임의의 노드 1에서 가장 먼 노드
//	if (visited[input] == 1) return;
//
//	visited[input] = 1;
//	if (graph[input].size() == 0) return; 
//	for (int i = 0; i < graph[input].size(); i++) {
//		int next_node = graph[input][i].first;
//		int weight = graph[input][i].second;
//
//		if (visited[next_node] == 1) continue;
//		else {
//			dist += weight;
//			if (dist > max_dist) {
//				max_dist = dist;
//				max_node = next_node;
//			}
//			//cout << dist << " dd ";
//			
//			dfs(next_node, dist);
//			dist -= weight;
//		}
//	}
//}
//
//int main(){
//	cin >> V;
//	for (int i = 1; i <= V; i++) {
//		int input;
//		cin >> input;
//		int connect, weight;
//		while (1) {
//			cin >> connect;
//			if (connect == -1) break;
//			else { 
//				cin >> weight; 
//				graph[input].push_back(make_pair(connect, weight));
//			}			
//		}			
//	}
//
//	// 임의의 노드에서 가장 먼 노드까지의 weight 
//	// 그 노드에서 가장 먼 노드까지의 weight
//
//	max_dist = 0;
//	max_node = 1;
//	dfs(1, 0);
//	//cout << "max_node " << max_node;
//
//	for (int i = 0; i <= 100001; i++) visited[i] = 0;
//	max_dist = 0;
//	dfs(max_node, 0);
//	cout << max_dist;
//}