//#include <iostream>
//
//using namespace std;
//
//int R, C;
//string input;
//int graph[21][21];
//int visited[27]; 
//int answer;
//
//int dx[4] = {1, -1, 0, 0};
//int dy[4] = {0, 0, 1, -1};
//
//void  dfs(int row, int col, int dist) {	
//	dist++;
//	if (dist > answer) answer = dist;
//
//	for (int d = 0; d < 4; d++) {
//		int next_x = row + dx[d];
//		int next_y = col + dy[d];
//
//		if (visited[graph[next_x][next_y]] != 1
//			&& next_x >= 1 && next_x <= R
//			&& next_y >= 1 && next_y <= C) {
//			visited[graph[next_x][next_y]] = 1;
//			dfs(next_x, next_y, dist);
//			visited[graph[next_x][next_y]] = 0;
//		}
//		//dfs(next_x, next_y, dist + 1);
//	}
//}
//
//int main() {
//	cin >> R >> C;
//
//	for (int i = 1; i <= R; i++) {
//		cin >> input;
//		for (int j = 0; j < C; j++) {
//			graph[i][j + 1] = input[j]- 'A' + 1;
//		}
//	}
//
//	answer = 0;
//	visited[graph[1][1]] = 1;
//	dfs(1, 1, 0);
//	cout << answer;
//}