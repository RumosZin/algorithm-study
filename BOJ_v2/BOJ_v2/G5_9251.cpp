#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string first;
string second;
int dp[1001][1001];

int main() {
	cin >> first >> second;

	for (int i = 0; i <= first.size(); i++) { // 0���� 6����
		for (int j = 0; j <= second.size(); j++) { // 0���� 6����
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
				continue;
			}

			// dp ���

			// 1. ���� ��� - ���� �밢�� ������ 1 ����
			if (first[i - 1] == second[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}

			// 2. �ٸ� ��� - ���� or ������ ū �� ����
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}

		}
	}
	cout << dp[first.size()][second.size()];
}