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
//			if (backpack[i][0] <= j) { // �ִ� ���Ը� �ϳ��� �÷����鼭 ���
//				if ((backpack[i][1] + dp[i - 1][j - backpack[i][0]])
//					> dp[i - 1][j]) { // ���� �ִ� ��ġ�� �̿��ϴ� �ͺ��� ������ ���� ���簡 �� ũ�ٸ� ����� ����
//					dp[i][j] = backpack[i][1] + dp[i - 1][j - backpack[i][0]]; // �ƴ϶�� ������ġ�� �̿�
//				}
//				else dp[i][j] = dp[i - 1][j];
//			}
//			else dp[i][j] = dp[i - 1][j];
//		}
//	}
//
//	cout << dp[N][K];
//}