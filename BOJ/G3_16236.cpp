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
//int result = 0; // �� �ɸ� �ð�
//int cnt = 0; // ����� ���� Ƚ��
//int sz = 2; // ��� ������
//
//bool stop = false; // ���� ����Ⱑ ���� ���
//bool eat = false; // �� ������ ���� ���
//
//void bfs(int a, int b, bool visit[][22], int shsize) {
//	queue<pair<pair<int, int>, int>> q;
//	q.push(make_pair(make_pair(a, b), 0));
//	visit[b][a] = true;
//	int temp; // �� ������ �Դµ� �ɸ� �ð�
//
//	while (!q.empty()) {
//		int x = q.front().first.first;
//		int y = q.front().first.second;
//		int count = q.front().second;
//
//		// ���� ������ �԰� �� ���� ������ ����
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
//				if (map[ny][nx] <= shsize) { // �������ų� ���� �� ����
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
//		if (eat) { // �Ծ��� ���
//			eat = false;
//			cnt += 1; // ����� ���� �� ����
//			map[by][bx] = 0; // ���� ����� ����
//			if (cnt == sz) { // ��� ������ ����
//				sz += 1;
//				cnt = 0;
//			}
//		}
//		else stop = true;
//	}
//
//	cout << result;
//}