#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int v[10];
int answer[10];
int visited[10];

void backtracking(int length) { // 지금까지의 길이
	
	
	if (length == M) {
		for (int i = 0; i < M; i++) {
			cout << answer[i]<< " ";
		}
		cout << "\n";
		return;
	}

	int last = 0;

	for (int i = 0; i < N; i++) {
		if (visited[i] == 0 && v[i] != last) {
			answer[length] = v[i];
			last = answer[length];
			visited[i] = 1;
			backtracking(length + 1);
			visited[i] = 0;
		}
	}

	return;
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;

		v[i] = input;
	}

	sort(v, v + N); 

	backtracking(0);
}