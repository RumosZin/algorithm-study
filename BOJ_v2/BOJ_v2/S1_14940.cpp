#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[1001][1001];
int visited[1001][1001];
int length_dist[1001][1001];
int goal_row, goal_col;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

typedef struct location {
	int row;
	int col;
	int dist;
};

queue<location> q;

void BFS() {
	while (!q.empty()) {

		// 1. current_row, current_col, current_dist 파악
		int current_row = q.front().row;
		int current_col = q.front().col;
		int current_dist = q.front().dist;

		//cout << "\t" << current_row << " " << current_col << " " << current_dist << "\n";
		q.pop();

		// 2. 상하좌우 4개의 위치에 대해 check하고 push
		for (int i = 0; i < 4; i++) {
			int next_row = current_row + dx[i];
			int next_col = current_col + dy[i];

			if (next_row >= 1 && next_row <= n
				&& next_col >= 1 && next_col <= m
				&& visited[next_row][next_col] != 1) {
				if (arr[next_row][next_col] == 1) {
					location loc = { next_row, next_col, current_dist + 1 };
					q.push(loc);
					visited[next_row][next_col] = 1;
					length_dist[next_row][next_col] = current_dist + 1;
				}
				else { // 0인 경우 dist가 0
					visited[next_row][next_col] = 1;
					continue;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int input;
			cin >> input;
			arr[i][j] = input;
		
			if (arr[i][j] == 2) {
				goal_row = i;
				goal_col = j;
			}
		}
	}

	location loc = { goal_row, goal_col, 0 };

	q.push(loc);
	visited[goal_row][goal_col] = 1;
	arr[goal_row][goal_col] = 0;

	BFS();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visited[i][j] != 1 && arr[i][j] == 1) cout << -1 << " ";
			else  cout << length_dist[i][j] << " ";
		}
		cout << "\n";
	}

}