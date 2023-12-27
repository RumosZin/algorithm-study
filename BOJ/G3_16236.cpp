//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int n;
//int map[22][22];
//int dx[4] = { 0, -1, 1, 0 };
//int dy[4] = { -1, 0, 0, 1 };
//
//int bx, by;
//int result = 0; // 총 걸린 시간
//int cnt = 0; // 물고기 먹은 횟수
//int sz = 2; // 상어 사이즈
//
//bool stop = false; // 먹을 물고기가 없는 경우
//bool eat = false; // 한 마리를 먹은 경우
//
//void bfs(int a, int b, bool visit[][22], int shsize) {
//	queue<pair<pair<int, int>, int>> q;
//	q.push(make_pair(make_pair(a, b), 0));
//	visit[b][a] = true;
//	int temp; // 한 마리를 먹는데 걸린 시간
//
//	while (!q.empty()) {
//		int x = q.front().first.first;
//		int y = q.front().first.second;
//		int count = q.front().second;
//
//		// 가장 위쪽을 먹고 그 다음 왼쪽을 먹음
//		if (map[y][x] > 0 && map[y][x] < shsize && temp == count) {
//			if ((by > y) || (by == y && bx > x)) {
//				by = y; bx = x; continue;
//			}
//		}
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//
//			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[ny][nx]) {
//				if (map[ny][nx] <= shsize) { // 지나가거나 먹을 수 있음
//					if (map[ny][nx] > 0 && map[ny][nx] < shsize && !eat) {
//						eat = true;
//						bx = nx;
//						by = ny;
//						temp = count + 1;
//						result += temp;
//					}
//					else {
//						q.push(make_pair(make_pair(nx, ny), count + 1));
//						//cout << nx << " " << ny << "\n";
//						visit[ny][nx] = true;
//					}
//				}
//			}
//		}
//		//cout << "\n";
//	}
//}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> map[i][j];
//			if (map[i][j] == 9) {
//				by = i; bx = j; map[i][j] = 0;
//			}
//		}
//	}
//
//	while (!stop) {
//		bool visit[22][22] = { 0 };
//		bfs(bx, by, visit, sz);
//		if (eat) { // 먹었을 경우
//			eat = false;
//			cnt += 1; // 물고기 먹은 수 증가
//			map[by][bx] = 0; // 먹은 물고기 삭제
//			if (cnt == sz) { // 상어 사이즈 증가
//				sz += 1;
//				cnt = 0;
//			}
//		}
//		else stop = true;
//	}
//
//	cout << result;
//}