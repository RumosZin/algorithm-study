//#include <iostream>
//#include <queue>
//#include <algorithm>
//#define INF 1000001
//
//using namespace std;
//
//int N, M;
//int graph[1001][1001];
//int visited[1001][1001][2]; 
//
//// [row][col][1] ���� �μ��� ������� ���� �ִ� �Ÿ�
//// [row][col][0] ���� �μ��� �ʰ� ������� ���� �ִ� �Ÿ�
//
//int dx[4] = {1, -1, 0, 0};
//int dy[4] = {0, 0, 1, -1};
//int answer;
//
//int main() {
//	cin >> N >> M;
//	string input;
//	for (int i = 1; i <= N; i++) {
//		cin >> input;
//		for (int j = 1; j <= M; j++) {
//			graph[i][j] = input[j - 1] - 48;
//		}
//	}
//
//	queue <pair<pair<int, int>, int>> q; // row, col, breaking
//	q.push(make_pair(make_pair(1, 1), 1));
//	visited[1][1][1] = 1;
//	visited[1][1][0] = 1;
//
//	answer = INF;
//
//	while (!q.empty()) {
//		int x = q.front().first.first;
//		int y = q.front().first.second;
//		int breaking = q.front().second; // breaking�� ������ Ƚ��
//		//cout << "(" << x << ", " << y << ") " << " " << visited[x][y][breaking] << "\n";
//
//		q.pop();
//
//		if (x == N && y == M) 
//		{
//			//cout << visited[N][M][0] << " " << visited[N][M][1];
//			answer = max(visited[N][M][0], visited[N][M][1]);
//			break;
//		}
//
//		for (int d = 0; d < 4; d++) {
//			int next_x = x + dx[d];
//			int next_y = y + dy[d];
//
//			if (next_x >= 1 && next_x <= N
//				&& next_y >= 1 && next_y <= M) { // ���� �־ �̵��� ������
//				if (graph[next_x][next_y] == 0 && visited[next_x][next_y][breaking] == 0) {// �Ⱥμŵ��Ǵ°��					
//					visited[next_x][next_y][breaking] = visited[x][y][breaking] + 1;
//					q.push(make_pair(make_pair(next_x, next_y), breaking));						
//				}
//				else if(graph[next_x][next_y] == 1 && breaking == 1){ // �μž� �ϴ� ���	
//					visited[next_x][next_y][0] = visited[x][y][breaking] + 1;
//					q.push(make_pair(make_pair(next_x, next_y), 0));											
//				}
//			}
//		}
//	}
//	if (answer == INF) cout << -1;
//	else cout << answer;
//}