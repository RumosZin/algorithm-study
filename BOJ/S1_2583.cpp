#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;
int arr[100][100];
int visited[100][100];
int area_num = 0;

queue <pair<int, int>> q; // 모눈 종이 탐색용
vector<int> v; // 넓이 기록용
int area = 0;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs() {

	while (!q.empty()) {

		int cur_row = q.front().first;
		int cur_col = q.front().second;
		//cout << "\t" << cur_row << " " << cur_col << "\n";
		area++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + dx[i];
			int next_col = cur_col + dy[i];

			if (next_row >= 0 && next_row < M
				&& next_col >= 0 && next_col < N
				&& visited[next_row][next_col] != 1
				&& arr[next_row][next_col] != 1) {
				visited[next_row][next_col] = 1;
				q.push({ next_row, next_col});
			}
		}
	}
	
}

int main() {

	// 1. input
	cin >> M >> N >> K;

	// 2. 직사각형이 그려지는 부분은 1로 세팅하기
	int left_row, left_col;
	int right_row, right_col;

	for (int i = 0; i < K; i++) {
		cin >> left_col >> left_row >> right_col >> right_row;

		for (int i = left_row; i < right_row; i++) {
			for (int j = left_col; j < right_col; j++) {
				arr[i][j] = 1;
			}
		}
	}

	//for (int i = 0; i < M; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	

	// 3. 모눈 종이를 돌면서, 영역의 갯수와 영역의 넓이 저장하기
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] != 1 && visited[i][j] != 1) {
				visited[i][j] = 1;
				q.push({ i, j});
				bfs();
				v.push_back(area);
				area = 0;
			}
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";

}


