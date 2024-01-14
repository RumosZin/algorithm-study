#include <iostream>
#define big 1000000000

using namespace std;

int N;
long long dp[101][3];

int main() {
	cin >> N;

	// 1. dp 구하기
	for (int i = 1; i <= 9; i++) dp[1][i] = 1;

	dp[1][0] = 0;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j + 1] % big;
			else if (j == 9) dp[i][j] = dp[i - 1][j - 1] % big;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % big;
		}
	}

	// 2. dp에서 N행 값 전부 더하기
	long long answer = 0; // 더한 값도 10의 9승을 넘어설 수 있으므로 주의!
	for (int i = 0; i <= 9; i++) answer += dp[N][i];
	cout << answer % big;
}