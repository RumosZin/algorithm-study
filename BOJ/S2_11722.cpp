//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//
//int answer;
//int num[1001];
//int dp[1001];
//
//int main() {
//	cin >> N;
//
//	for (int i = 1; i <= N; i++) {
//		cin >> num[i];		
//	}
//
//	int answer = 0;
//	for (int i = 1; i <= N; i++) {
//		dp[i] = 1;
//		for (int j = 1; j <= i; j++) {
//			if (num[i] < num[j] && dp[j] + 1 > dp[i]) { dp[i] = dp[j] + 1; }
//		}
//	}
//
//	for (int i = 1; i <= N; i++) {
//		if (dp[i] > answer) answer = dp[i];
//	}
//
//	cout << answer;
//}