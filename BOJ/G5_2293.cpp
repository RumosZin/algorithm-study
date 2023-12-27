//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int n, k;
//int coin[101];
//int dp[10001] = { 0, };
//
//int main() {
//
//	cin >> n >> k;
//	int count = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> coin[i];
//	}
//	n = n - count;
//	dp[0] = 1;
//	for (int i = 1; i <= n; i++) {
//		for (int j = coin[i]; j <= k; j++) {
//			dp[j] += dp[j - coin[i]];
//		}
//	}
//	cout << dp[k];
//}