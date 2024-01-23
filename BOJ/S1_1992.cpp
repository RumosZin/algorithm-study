#include <iostream>
#include <string>

using namespace std;

int N;
int arr[64][64];

void d_and_c(int row, int col, int n) {
	
	for (int i = row; i < row + n; i++) {
		for (int j = col; j < col + n; j++) {
			if (arr[i][j] != arr[row][col]) {
				cout << "(";
				d_and_c(row, col, n / 2);
				d_and_c(row, col + n / 2, n / 2);
				d_and_c(row + n / 2, col, n / 2);
				d_and_c(row + n / 2, col + n / 2, n / 2);
				cout << ")";
				return;
			}
		}
	}
	cout << arr[row][col];
}

int main() {

	// 1. input
	int zero = 0;
	int one = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < N; j++) {
			arr[i][j] = input[j] - '0';
		}
	}

	// 2. divide and conquer
	d_and_c(0, 0, N);


}