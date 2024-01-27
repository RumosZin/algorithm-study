#include <iostream>
#include <vector>

using namespace std;

int N, M;
int visited[9];
int arr[9]; // M까지 순서대로 담기도록 처리

void backtracking(int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] != 1) {
			visited[i] = 1;
			arr[count] = i;
			backtracking(count + 1);
			visited[i] = 0;
		}
	}
}

int main() {

	// 1. input
	cin >> N >> M;

	// 2. backtracking
	backtracking(0);
}