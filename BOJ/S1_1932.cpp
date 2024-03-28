#include <iostream>
#include <queue>

using namespace std;

// Ư������ �ִ� BFS
int n;
int triangle[501][501];
int answer = 0;

typedef struct location {
	int row;
	int col;
	int total;
	// row, col�� �˸� value�� �� �� ����
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

		// 1. n == 1 : ��ġ�� �� Ȯ������ ����
		if (n == 1) {
			q.push({ current_row + 1, current_col });
			q.push({ current_row + 1, current_col + 1 });
		}
		
		// 2. n != 1 : �̿��� �ͳ��� ��ġ�� �� maximum ���� Ȯ���ؾ� ��
		else {
			if (current_col == 1) { // ������ �ʰ� q�� push
				q.push({ current_row + 1, current_col, current_total + triangle[current_row + 1][current_col]});
				q.push({ current_row + 1, current_col + 1, current_total + triangle[current_row + 1][current_col + 1] });
			}
			else { // q�� ���� ������ ���� ���ؼ� push
				if (q.back().total < current_total + triangle[current_row + 1][current_col]) { // ���߿� ���� ���� �� ū ���
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