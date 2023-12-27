//#include <iostream>
//
//using namespace std;
//
//int graph[51][51];
//int newgraph[51][51];
//int R, C, T;
//int up, down;
//
//int dx[4] = { 1, -1, 0, 0 };
//int dy[4] = { 0, 0, 1, -1 };
//
//void spread() { // 미세먼지 확산
//	for (int i = 1; i <= R; i++) {
//		for (int j = 1; j <= C; j++) {
//			if (graph[i][j] == -1) {
//				newgraph[i][j] = -1;
//				continue;
//			}
//			int spreadnum = 0;
//			bool freshtool = false;
//			int init = graph[i][j];
//
//			for (int d = 0; d < 4; d++) { // 주변 네 방향에서 영향을 받음
//				int row = i + dx[d];
//				int col = j + dy[d];
//
//				if (row >= 1 && row <= R
//					&& col >= 1 && col <= C) { // 상하좌우 칸이 유효한 칸
//						newgraph[i][j] += graph[row][col] / 5;
//						spreadnum++; 
//						if (graph[row][col] == -1) freshtool = true;
//				}
//			}
//			if (freshtool) spreadnum--;
//			newgraph[i][j] -= (init / 5) * spreadnum;
//			newgraph[i][j] += graph[i][j];
//		}
//	}
//
//	for (int i = 1; i <= R; i++) {
//		for (int j = 1; j <= C; j++) {
//			graph[i][j] = newgraph[i][j];
//		}
//	}
//}
//
//void fresh() {
//	// 1열 up, down 나눠서
//	for (int i = up - 1; i >= 2; i--) {	graph[i][1] = graph[i - 1][1];}
//	graph[1][1] = graph[1][2];
//
//	for (int i = down + 1; i <= R - 1; i++) { graph[i][1] = graph[i + 1][1]; }
//	if (down != R) graph[R][1] = graph[R][2];
//
//	//맨 아랫 줄, 맨 윗줄
//	for (int i = 1; i <= C - 1; i++) {
//		if(up != 1) graph[1][i] = graph[1][i + 1];
//		if(down != R) graph[R][i] = graph[R][i + 1];
//	}
//	if (up != 1) graph[1][C] = graph[2][C];
//	if (down != R) graph[R][C] = graph[R - 1][C];
//
//	for (int i = 2; i <= up - 1; i++) { graph[i][C] = graph[i + 1][C]; }
//	for (int i = R - 1; i >= down + 1; i--) { graph[i][C] = graph[i - 1][C]; }
//
//	// up, down이 속한 줄
//	for (int i = C; i >= 2; i--) {
//		graph[up][i] = graph[up][i - 1];
//		graph[down][i] = graph[down][i - 1];
//	}
//	graph[up][2] = 0;
//	graph[down][2] = 0;
//}
//
//int main() {
//	cin >> R >> C >> T;
//	for (int i = 1; i <= R; i++) {
//		for (int j = 1; j <= C; j++) {
//			cin >> graph[i][j];
//			if (graph[i][j] == -1) down = i;
//			newgraph[i][j] = 0;
//		}
//	}
//
//	up = down - 1;
//	// cout << up << "dd";
//
//	
//	for (int t = 1; t <= T; t++) {
//		spread();
//		fresh();	
//
//		for (int i = 1; i <= R; i++) {
//			for (int j = 1; j <= C; j++) {
//				newgraph[i][j] = 0;
//			}
//		}
//	}
//	int answer = 0;
//	for (int i = 1; i <= R; i++) {
//		for (int j = 1; j <= C; j++) {
//			answer += graph[i][j];
//		}
//	}
//	cout << answer + 2;
//
//}