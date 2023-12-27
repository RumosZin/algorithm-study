//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int graph[4][100002];
//int dp[4][100002];
//
//int T, n;
//int answer;
//
//int main() {
//	cin >> T;
//	for (int t = 1; t <= T; t++) {
//		answer = 0;
//		cin >> n;
//		for (int i = 1; i <= 2; i++) {
//			for (int j = 1; j <= n; j++) {
//				cin >> graph[i][j];
//			}
//		}
//
//		dp[1][1] = graph[1][1];
//		dp[2][1] = graph[2][1];
//		dp[1][2] = dp[2][1] + graph[1][2];
//		dp[2][2] = dp[1][1] + graph[2][2];
//		
//		for (int i = 3; i <= n; i++) {
//			dp[1][i] = graph[1][i] + max(dp[2][i - 1], dp[2][i - 2]);
//			dp[2][i] = graph[2][i] + max(dp[1][i - 1], dp[1][i - 2]);
//		}
//
//		answer = max(dp[1][n], dp[2][n]);
//
//		cout << answer << "\n";
//	}
//}