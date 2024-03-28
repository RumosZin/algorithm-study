#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[101][101];
long long dp[101][101] = { 0, };
int answer = 0;

void solution() {
	for(int row = 1; row <= N; row++) {
		for (int col = 1; col <= N; col++) {
			int count = arr[row][col];

			

			if (dp[row][col] == 0 || arr[row][col] == 0) { continue; }

			// 아직 이동 중이면
			if (row + count <= N) dp[row + count][col] += dp[row][col];
			
			if (col + count <= N) dp[row][col + count] += dp[row][col];
			//cout << "\t" << row << " " << col << " " << count << "\n";
		}	
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	dp[1][1] = 1;
	solution();
	cout << dp[N][N];
}