#include <iostream>
#include <queue>

using namespace std;

// 특수성이 있는 BFS
int n;
int triangle[501][501];
int answer = 0;

typedef struct location {
	int row;
	int col;
	int total;
	// row, col을 알면 value를 알 수 있음
};

queue<location> q;

void BFS() {
	while (!q.empty()) {
		int current_row = q.front().row;
		int current_col = q.front().col;
		int current_total = q.front().total;
		int current_value = triangle[current_row][current_col];
		q.pop();

		// 0. current_Row == n
		if (current_row == n) {
			if (answer <= current_total) answer = current_total;
			continue;
		}

		// 1. n == 1 : 겹치는 것 확인하지 않음
		if (n == 1) {
			q.push({ current_row + 1, current_col });
			q.push({ current_row + 1, current_col + 1 });
		}
		
		// 2. n != 1 : 이웃한 것끼리 겹치는 것 maximum 값을 확인해야 함
		else {
			if (current_col == 1) { // 비교하지 않고 q에 push
				q.push({ current_row + 1, current_col, current_total + triangle[current_row + 1][current_col]});
				q.push({ current_row + 1, current_col + 1, current_total + triangle[current_row + 1][current_col + 1] });
			}
			else { // q의 가장 마지막 값과 비교해서 push
				if (q.back().total < current_total + triangle[current_row + 1][current_col]) { // 나중에 계산된 값이 더 큰 경우
					q.back().row = current_row + 1;
					q.back().col = current_col;
					q.back().total = current_total + triangle[current_row + 1][current_col];
				}
				q.push({ current_row + 1, current_col + 1, current_total + triangle[current_row + 1][current_col + 1] });
			}
		}
	}
}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int input;
			cin >> input;
			triangle[i][j] = input;
		}
	}


	q.push({ 1, 1, triangle[1][1] }); // (7, 7, 1)
	BFS();

	cout << answer;

}