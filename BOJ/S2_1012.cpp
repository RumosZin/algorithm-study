//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int T;
//int M, N, K;
//int answer = 0;
//
//typedef struct location {
//	int row;
//	int col;
//};
//
//vector<location> v;
//int visited[51][51];
//int arr[51][51];
//
//int dx[4] = { 0, 0, 1, -1 };
//int dy[4] = { 1, -1, 0, 0 };
//
//void DFS(int col, int row) {
//	//cout << "d" << row << " " << col <<  " " << answer << "\n";
//	visited[col][row] = 1;
//
//	for (int i = 0; i < 4; i++) {
//		int next_row = row + dx[i];
//		int next_col = col + dy[i];
//
//		if (next_row >= 0 && next_row <= M - 1
//			&& next_col >= 0 && next_col <= N - 1
//			&& visited[next_col][next_row] != 1
//			&& arr[next_col][next_row] == 1) { // 범위에 들기 + 방문한 적 없음
//			visited[next_col][next_row] = 1;
//			DFS(next_col, next_row);
//			//visited[next_col][next_row] = 0;
//		}
//	}
//}
//
//int main() {
//	cin >> T;
//	for (int i = 1; i <= T; i++) {
//
//		cin >> M >> N >> K;
//		answer = 0;
//		for (int p = 0; p < 51; p++) {
//			for (int q = 0; q < 51; q++) {
//				arr[p][q] = 0;
//				visited[p][q] = 0;
//			}
//		}
//		v.clear();
//
//
//		for (int j = 0; j < K; j++) {
//			int row, col;
//			cin >> row >> col;
//			v.push_back({ row, col });
//			arr[col][row] = 1;
//		}
//
//		for (int k = 0; k < K; k++) { // v에 대해서 DFS 수행
//			int current_row = v[k].row;
//			int current_col = v[k].col;
//
//			if (visited[current_col][current_row] != 1) {
//				//visited[current_row][current_col] = 1;
//				answer++;
//				DFS(current_col, current_row);
//			}
//		}
//
//		cout << answer << "\n";
//	}
//}