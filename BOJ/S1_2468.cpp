#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int area[101][101];
int visited[101][101] = { 0, };

typedef struct location {
	int row;
	int col;
};

queue<location> q;
vector<int> v;

int height_max = 0;
// int height_min = 101;
int height;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs() {

	while (!q.empty()) {
		int current_row = q.front().row;
		int current_col = q.front().col;
		//cout << "\t" << current_row << " " << current_col << "\n";

		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_row = current_row + dx[i];
			int next_col = current_col + dy[i];

			if (next_row >= 0 && next_row < N
				&& next_col >= 0 && next_col < N
				&& visited[next_row][next_col] != 1
				&& area[next_row][next_col] > height) {
				visited[next_row][next_col] = 1;
				q.push({ next_row, next_col });
			}
		}
	}
}

int main() {

	// 1. area height info input
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> area[i][j];

			if (height_max < area[i][j]) height_max = area[i][j];
			//if (height_min > area[i][j]) height_min = area[i][j];
		}
	}

	// 2. bfs [height_max ~ height_min]	
	for (int i = height_max; i >= 0; i--) {
		height = i; // i
		int safe_area = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (area[i][j] > height && visited[i][j] != 1) {
					visited[i][j] = 1;
					safe_area++;
					q.push({i, j}); // 일단 하나 넣고
					bfs();
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = 0;
			}
		}

		v.push_back(safe_area);
		//cout << height << " " <<  safe_area << "dd\n";

	}

	int answer = 0;
	for (int i = 0; i < v.size(); i++) {
		if (answer < v[i]) answer = v[i];
	}

	cout << answer;
}