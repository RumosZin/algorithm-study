//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int graph[1001][1001];
//int visited[1001][1001];
//
//int M, N;
//queue<pair<int, int>> q;
//
//int dx[] = { 1, -1, 0, 0 };
//int dy[] = { 0, 0, 1, -1 };
//
//int answer;
//
//int main() {
//	cin >> M >> N;
//	int tomato;
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			cin >> tomato;
//			graph[i][j] = tomato;
//			if (graph[i][j] == 1) { // tomato가 있는 위치면
//				q.push(make_pair(i, j));
//			}
//			if (graph[i][j] == -1) visited[i][j] = 1; // -1이면 벽이니까 visited 1로 설정
//		}
//	}
//
//	while (!q.empty()) {
//		int row = q.front().first;
//		int col = q.front().second;
//
//		q.pop();
//
//		visited[row][col] = 1;
//
//		for (int d = 0; d < 4; d++) {
//			int next_x = row + dx[d];
//			int next_y = col + dy[d];
//
//			if (next_x >= 1 && next_x <= N
//				&& next_y >= 1 && next_y <= M
//				&& graph[next_x][next_y] == 0
//				&& visited[next_x][next_y] != 1) {
//				graph[next_x][next_y] = graph[row][col] + 1;
//				q.push(make_pair(next_x, next_y));
//			}
//		}
//	}
//
//	bool check = true;
//	int max = 0;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			if (graph[i][j] > max) max = graph[i][j];
//			if (visited[i][j] != 1) {
//				check = false;
//				cout << -1;
//				break;
//			}
//			// 1이 아닌 것이 있다면 그 토마토는 익을 수 없음
//		}
//		if (!check) break;
//	}
//	answer = max;
//	if (check) { cout << answer - 1; }
//}