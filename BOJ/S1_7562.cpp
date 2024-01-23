#include <iostream>
#include <queue>

using namespace std;

int T;
int L; // 한 변의 길이
int start_row, start_col;
int end_row, end_col;
int visited[300][300];
int answer;

typedef struct location {
	int row;
	int col;
	int move;
};

queue<location> q;

int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

void bfs() {
	while (!q.empty()) {
		int cur_row = q.front().row;
		int cur_col = q.front().col;
		int cur_move = q.front().move;

		q.pop();

		if (cur_row == end_row
			&& cur_col == end_col) {
			answer = cur_move;
			return;
		}

		for (int i = 0; i < 8; i++) {
			int next_row = cur_row + dx[i];
			int next_col = cur_col + dy[i];

			if (next_row >= 0 && next_row < L
				&& next_col >= 0 && next_col < L
				&& visited[next_row][next_col] != 1) {
				visited[next_row][next_col] = 1;
				q.push({ next_row, next_col, cur_move + 1 });
			}
		}
	}
}


int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> L;

		cin >> start_row >> start_col;
		cin >> end_row >> end_col;

		// visited, q 비우기
		while (!q.empty())q.pop();
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < L; j++) {
				visited[i][j] = 0;
			}
		}

		visited[start_row][start_col] = 1;
		q.push({ start_row, start_col, 0 });
		bfs();

		cout << answer << "\n";


	}
}