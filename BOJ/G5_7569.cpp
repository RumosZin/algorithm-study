#include <iostream>
#include <queue>

using namespace std;

int graph[101][101][101]; // 이차원 벡터 선언을 너무 많이 할 경우 이렇게 배열로 선언
int visited[101][101][101];

int M, N, H;
queue<pair<pair<int, int>, int>> q;

/**
 * 3차원에서 dx, dy, dz 좌표 표현 방법
*/
int dx[] = { 1, -1, 0, 0, 0, 0};
int dy[] = { 0, 0, 1, -1, 0, 0};
int dz[] = { 0, 0, 0, 0, 1, -1};

int answer;

int main() {
	cin >> M >> N >> H;
	int tomato;

	for (int k = 1; k <= H; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {

				cin >> tomato;
				graph[i][j][k] = tomato;
				if (graph[i][j][k] == 1) { // 익은 토마토
					q.push(make_pair(make_pair(i, j), k));
                    visited[i][j][k] = 1;
				}
				if (graph[i][j][k] == -1) visited[i][j][k] = 1; // -1인 곳은 방문 체크해도 된다

			}
		}
	}
	

	while (!q.empty()) {
		int row = q.front().first.first;
		int col = q.front().first.second;
		int height = q.front().second;

		q.pop();

		for (int d = 0; d < 6; d++) {
			int next_x = row + dx[d];
			int next_y = col + dy[d];
			int next_z = height + dz[d];

            // x, y, z, 각각 범위 확인
            // 그래프 0인지 확인
            // 방문하지 않았는지 확인
			if (next_x >= 1 && next_x <= N
				&& next_y >= 1 && next_y <= M
				&& next_z >= 1 && next_z <= H
				&& graph[next_x][next_y][next_z] == 0
				&& visited[next_x][next_y][next_z] != 1) {
				graph[next_x][next_y][next_z] = graph[row][col][height] + 1;
				q.push(make_pair(make_pair(next_x, next_y), next_z));
                visited[next_x][next_y][next_z] = 1;
			}
		}
	}

    // 익지 않은 토마토 있는지 확인
	bool check = true;
	int max = 0;
	for (int k = 1; k <= H; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (graph[i][j][k] > max) max = graph[i][j][k];
				if (visited[i][j][k] != 1) {
					check = false;
					cout << -1;
					break;
				}				
			}
			if (!check) break;
		}
		if (!check) break;
	}
	
	answer = max;
	if (check) { cout << answer - 1; }
}