#include <iostream>

#define mod 9901;

using namespace std;


int N;
int dp[100001][3]; // dp[i][j] : i번째 행에 j번째 방법을 적용한 경우의 수

int main() {
	cin >> N;
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
	}

	cout << (dp[N][0] + dp[N][1] + dp[N][2]) % mod;

}