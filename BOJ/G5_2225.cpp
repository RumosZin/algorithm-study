//#include <iostream>
//
//using namespace std;
//
//int N, K;
//int dp[201][201];
//
//
//int main() {
//
//	cin >> N >> K;
//	for (int i = 0; i <= N; i++) { dp[1][i] = 1; }
//	for (int i = 0; i <= K; i++) dp[i][0] = 1;
//	
//	for (int i = 2; i <= K; i++) {
//		for (int j = 1; j <= N; j++) {
//			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
//		}
//	}
//
//	cout << dp[K][N] % 1000000000;
//}