//#include <iostream>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//int K; // 말이 될 수 있는 횟수
//int W, H; // width, height
//int graph[201][201]; // 격자무늬
//int visited[201][201][30];
//
//struct location {
//	int row, col;
//	int moving;
//	int horse;
//};
//
//queue<location> q;
//
//int dx[4] = { 1, -1, 0, 0 };
//int dy[4] = { 0, 0, 1, -1 };
//
//int hx[8] = { 1, 1, 2, 2, -1, -1, -2, -2 };
//int hy[8] = { 2, -2, 1, -1, 2, -2, 1, -1 };
//
//int answer;
//
//int main() {
//	cin >> K >> W >> H;
//	answer = 0;
//	bool find = false;
//
//	for (int i = 1; i <= H; i++) {
//		for (int j = 1; j <= W; j++) {
//			cin >> graph[i][j];
//		}
//	}
//
//	q.push({ 1, 1, 0, 0 });
//	visited[1][1][0] = 1;
//	
//	while (!q.empty()) {
//		int x = q.front().row;
//		int y = q.front().col;
//		int move = q.front().moving;
//		int horsemove = q.front().horse;
//		//cout << "(" << x << ", " << y << ", " << horsemove << ") ";
//
//		q.pop();
//
//		if (x == H && y == W) {
//			cout << move;
//			find = true;
//			break;
//		}
//
//		for (int d = 0; d < 4; d++) {
//			int next_x = x + dx[d];
//			int next_y = y + dy[d];
//
//			if (next_x >= 1 && next_x <= H
//				&& next_y >= 1 && next_y <= W
//				&& graph[next_x][next_y] != 1
//				&& visited[next_x][next_y][horsemove] != 1) {
//
//				q.push({ next_x, next_y, move + 1, horsemove });
//				visited[next_x][next_y][horsemove] = 1;
//				//cout << "(" << next_x << ", " << next_y << ", " << horsemove << ")";
//			}
//		}
//
//		for (int h = 0; h < 8; h++) {
//			int next_x = x + hx[h];
//			int next_y = y + hy[h];
//
//			if (next_x >= 1 && next_x <= H
//				&& next_y >= 1 && next_y <= W
//				&& graph[next_x][next_y] != 1
//				&& visited[next_x][next_y][horsemove + 1] != 1
//				&& horsemove < K) {
//
//				q.push({ next_x, next_y, move + 1, horsemove + 1 });
//				visited[next_x][next_y][horsemove + 1] = 1;
//				//cout << "(" << next_x << ", " << next_y << ")";
//			}
//		}
//		//cout << "\n";
//	}
//	if(!find) cout << -1;
//}