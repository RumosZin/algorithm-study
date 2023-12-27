//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int visited[100001];
//queue<pair<int, int>> q;
//
//int N, K;
//
//void BFS(int N) {
//	q.push(make_pair(N, 0));
//
//	while (!q.empty()) {
//		int x = q.front().first;
//		int count = q.front().second;
//		q.pop();
//
//		if (x == K) {
//			cout << count;
//			break;
//		}
//		if (x + 1 >= 0 && x + 1 < 100001) {
//			if (visited[x + 1] != 1) { // 방문하지 않았으면
//				visited[x + 1] = 1;
//				q.push(make_pair(x + 1, count + 1));
//
//			}
//		}
//		if (x - 1 >= 0 && x - 1 < 100001) {
//			if (visited[x - 1] != 1) {
//				visited[x - 1] = 1;
//				q.push(make_pair(x - 1, count + 1));
//			}
//		}
//		if (2 * x >= 0 && 2 * x < 100001) {
//			if (visited[2 * x] != 1) {
//				visited[2 * x] = 1;
//				q.push(make_pair(2 * x, count + 1));
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> N >> K;
//	
//	visited[N] = 1;
//	BFS(N);
//	return 0;	
//}