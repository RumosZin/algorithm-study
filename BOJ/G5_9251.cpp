#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string first;
string second;
int dp[1001][1001];

int main() {
	cin >> first >> second;

	for (int i = 0; i <= first.size(); i++) { // 0부터 6까지
		for (int j = 0; j <= second.size(); j++) { // 0부터 6까지
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
				continue;
			}

			// dp 계산

			// 1. 같은 경우 - 왼쪽 대각선 위에서 1 증가
			if (first[i - 1] == second[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}

			// 2. 다른 경우 - 왼쪽 or 위에서 큰 값 적용
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}

		}
	}
	cout << dp[first.size()][second.size()];
}