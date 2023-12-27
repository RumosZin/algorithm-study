//#include <iostream>
//
//using namespace std;
//
//int dp[1001];
//int n;
//int answer;
//
//
//int main() {
//	cin >> n;
//
//	int width = 0;
//	for (int i = 1; i != n; i++) {
//		if (2 * i == n || 2 * i == n - 1) {
//			width = i;
//			break;
//		}
//	}
//	
//	dp[1] = 1;
//	dp[2] = 2;
//
//	for (int i = 3; i <= n; i++) {
//		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
//	}
//	cout << dp[n];
//}