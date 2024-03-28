//#include <iostream>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//int M, N;
//int dx[5] = { 0, 0, 0, 1, -1 };
//int dy[5] = { 0, 1, -1, 0, 0 };
//
//int factory[101][101];
//int visited[101][101][5];
//
//int start_row, start_col, start_dir;
//int end_row, end_col, end_dir;
//int answer = 10000;
//
//typedef struct location {
//	int row;
//	int col;
//	int dir;
//	int count;
//};
//
//queue<location> q;
//
//void BFS() {
//
//
//	while (!q.empty()) {
//
//		int current_row = q.front().row;
//		int current_col = q.front().col;
//		int current_dir = q.front().dir;
//		int current_count = q.front().count;
//		q.pop();
//
//		//cout << current_row << " " << current_col << " " << current_dir << " " << current_count << "d\n";
//
//		if (current_row == end_row
//			&& current_col == end_col
//			&& current_dir == end_dir) {
//			if (answer > current_count) answer = current_count;
//			//return;
//		}
//
//		// ÇØ´ç ¹æÇâ¿¡¼­ 1, 2, 3Ä­
//		for (int i = 1; i <= 3; i++) {
//			int next_row = current_row + dx[current_dir] * i;
//			int next_col = current_col + dy[current_dir] * i;
//			//cout << "next_row " << next_row << "next_col " << next_col << "\n";
//
//			if (visited[next_row][next_col][current_dir] == 1) continue;
//
//
//			// visited È®ÀÎ
//			if (next_row >= 1 && next_row <= M
//				&& next_col >= 1 && next_col <= N
//				&& factory[next_row][next_col] == 0) {
//				visited[next_row][next_col][current_dir] = 1;
//				q.push({ next_row, next_col, current_dir, current_count + 1 });
//				//cout << "d" << current_dir << "d" << "\n";
//			}
//			else break; // ¶Õ°í 2Ä­, 3Ä­ °¥ ¼ö ¾øÀ½
//		}
//
//		// ¹æÇâ ÀüÈ¯
//		for (int i = 1; i <= 4; i++) {
//			if (current_dir != i && visited[current_row][current_col][i] != 1) {
//				visited[current_row][current_col][i] = 1;
//				if ((current_dir == 1 && i == 2)
//					|| (current_dir == 2 && i == 1)
//					|| (current_dir == 3 && i == 4)
//					|| (current_dir == 4 && i == 3)) q.push({ current_row, current_col, i, current_count + 2 });
//				else q.push({current_row, current_col, i, current_count + 1});
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> M >> N;
//	for (int i = 1; i <= M; i++) {
//		for (int j = 1; j <= N; j++) {
//			cin >> factory[i][j];
//		}
//	}
//
//	cin >> start_row >> start_col >> start_dir;
//	cin >> end_row >> end_col >> end_dir;
//
//	q.push({ start_row, start_col, start_dir, 0 });
//	visited[start_row][start_col][start_dir] = 1;
//
//	BFS();
//
//	cout << answer;
//
//}