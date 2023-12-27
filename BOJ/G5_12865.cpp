//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int N, K;
//int dp[101][100001];
//int backpack[101][2];
//
//int main() {
//	cin >> N >> K;
//
//	int weight, value;
//	for (int i = 1; i <= N; i++) {
//		cin >> weight >> value;
//		backpack[i][0] = weight;
//		backpack[i][1] = value;
//	}
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= K; j++) {
//			if (backpack[i][0] <= j) { // 최대 무게를 하나씩 올려가면서 계산
//				if ((backpack[i][1] + dp[i - 1][j - backpack[i][0]])
//					> dp[i - 1][j]) { // 이전 최대 가치를 이용하는 것보다 이전걸 빼고 현재가 더 크다면 현재로 변경
//					dp[i][j] = backpack[i][1] + dp[i - 1][j - backpack[i][0]]; // 아니라면 이전가치를 이용
//				}
//				else dp[i][j] = dp[i - 1][j];
//			}
//			else dp[i][j] = dp[i - 1][j];
//		}
//	}
//
//	cout << dp[N][K];
//}