//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int graph[101][101][101];
//int visited[101][101][101];
//
//int M, N, H;
//queue<pair<pair<int, int>, int>> q;
//
//int dx[] = { 1, -1, 0, 0, 0, 0};
//int dy[] = { 0, 0, 1, -1, 0, 0};
//int dz[] = { 0, 0, 0, 0, 1, -1};
//
//int answer;
//
//int main() {
//	cin >> M >> N >> H;
//	int tomato;
//
//	for (int k = 1; k <= H; k++) {
//		for (int i = 1; i <= N; i++) {
//			for (int j = 1; j <= M; j++) {
//
//				cin >> tomato;
//				graph[i][j][k] = tomato;
//				if (graph[i][j][k] == 1) { // tomato가 있는 위치면
//					q.push(make_pair(make_pair(i, j), k));
//				}
//				if (graph[i][j][k] == -1) visited[i][j][k] = 1; // -1이면 벽이니까 visited 1로 설정
//
//			}
//		}
//	}
//	
//
//	while (!q.empty()) {
//		int row = q.front().first.first;
//		int col = q.front().first.second;
//		int height = q.front().second;
//
//		q.pop();
//
//		visited[row][col][height] = 1;
//
//		for (int d = 0; d < 6; d++) {
//			int next_x = row + dx[d];
//			int next_y = col + dy[d];
//			int next_z = height + dz[d];
//
//			if (next_x >= 1 && next_x <= N
//				&& next_y >= 1 && next_y <= M
//				&& next_z >= 1 && next_z <= H
//				&& graph[next_x][next_y][next_z] == 0
//				&& visited[next_x][next_y][next_z] != 1) {
//				graph[next_x][next_y][next_z] = graph[row][col][height] + 1;
//				q.push(make_pair(make_pair(next_x, next_y), next_z));
//			}
//		}
//	}
//
//	bool check = true;
//	int max = 0;
//	for (int k = 1; k <= H; k++) {
//		for (int i = 1; i <= N; i++) {
//			for (int j = 1; j <= M; j++) {
//				//cout << graph[i][j][k];
//				if (graph[i][j][k] > max) max = graph[i][j][k];
//				if (visited[i][j][k] != 1) {
//					check = false;
//					cout << -1;
//					break;
//				}				
//			}
//			if (!check) break;
//		}
//		if (!check) break;
//	}
//	
//	answer = max;
//	if (check) { cout << answer - 1; }
//}