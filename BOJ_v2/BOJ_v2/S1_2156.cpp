#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[10001];
int dp[10001];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	// DP °è»ê
	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];

	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		dp[i] = max(dp[i - 1], dp[i]);
	}

	cout << dp[N];

}