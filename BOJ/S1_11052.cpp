#include <iostream>

using namespace std;

int N;
long long value[1001];
long long dp[1001] = { 0, };

int main() {


	cin >> N;
	for (int i = 1; i <= N; i++) cin >> value[i];

	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			int temp = dp[j - 1] + value[i - j + 1];
			if (dp[i] < temp) dp[i] = temp;
		}
	}

	cout << dp[N];
}