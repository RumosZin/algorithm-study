//#include <iostream>
//
//using namespace std;
//
//int T;
//int dp[12];
//
//int main() {
//	cin >> T;
//	dp[1] = 1;
//	dp[2] = 2;
//	dp[3] = 4;
//	for (int t = 1; t <= T; t++) {
//		int num;
//		cin >> num;
//		if (num == 1) { cout << dp[1] << "\n"; continue; }
//		if (num == 2) { cout << dp[2] << "\n"; continue; }
//		if (num == 3) { cout << dp[3] << "\n"; continue; }
//
//		for (int i = 4; i <= num; i++) {
//			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
//		}
//		cout << dp[num] << "\n";
//	}
//}