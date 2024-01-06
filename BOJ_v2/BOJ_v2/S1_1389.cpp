#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
int arr[1001][1001];
int visited[1001][1001][11];
int answer;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

typedef struct location {
	int row;
	int col;
	int k;
	int dist;
};
queue<location> q;

void BFS() {

	while (!q.empty()) {
		int current_row = q.front().row;
		int current_col = q.front().col;
		int current_k = q.front().k;
		int current_dist = q.front().dist;
		q.pop();

		if (current_row == N
			&& current_col == M) {
			answer = current_dist;
			return;
		}

		// 네 방향 확인

		for (int i = 0; i < 4; i++) {
			int next_row = current_row + dx[i];
			int next_col = current_col + dy[i];

			// 0이면 이동한다. k 유지, dist + 1
			if (next_row >= 1 && next_row <= N
				&& next_col >= 1 && next_col <= M
				&& arr[next_row][next_col] == 0
				&& visited[next_row][next_col][current_k] != 1) {
				visited[next_row][next_col][current_k] = 1;
				q.push({next_row, next_col, current_k, current_dist + 1});
			}
			else if (next_row >= 1 && next_row <= N
				&& next_col >= 1 && next_col <= M
				&& arr[next_row][next_col] == 1
				&& visited[next_row][next_col][current_k + 1] != 1) { // 1인 경우 부수고 이동할 수 있는지 확인

				if (current_k < K) {
					visited[next_row][next_col][current_k + 1] = 1;
					q.push({ next_row, next_col, current_k + 1, current_dist + 1 });
				}
				else continue;

			}
		}

	}
}


int main() {
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < M; j++) {
			if (input[j] == '0') arr[i][j + 1] = 0;
			else arr[i][j + 1] = 1;
		}
	}

	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << arr[i][j] << " ";

		}
		cout << "\n";
	}*/

	visited[1][1][0] = 1;
	q.push({1, 1, 0, 0});

	BFS();

	if (answer == 0 && N != 1 && M != 1) cout << -1;
	else if (N == 1 && M == 1) cout << 1;
	else 	cout << answer + 1;


}