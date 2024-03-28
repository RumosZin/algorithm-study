#include <iostream>

using namespace std;

int dp[1001][10] = { 0, }; // N, 0บฮลอ 9
int input;
int answer = 0;

int main() {
	cin >> input;

	for (int i = 0; i < 10; i++) dp[1][i] = 1;
	for (int i = 0; i < 10; i++) dp[2][i] = i + 1;

	bool find = false;
	int num = 3;

	if (input == 1) {
		answer = 10;
		find = true;
	}
	else if (input == 2) {
		answer = 55;
		find = true;
	}

	
	while (!find) {
		if (num == input) find = true;
		for (int i = 0; i < 10; i++) {
			if (i == 0) {
				dp[num][i] = 1;
				continue;
			}
			dp[num][i] = (dp[num][i - 1] + dp[num - 1][i]) % 10007;
		}
		num++;
	}

	if(input >= 3) 	for (int i = 0; i < 10; i++) answer += dp[input][i];
	if (answer >= 10007) answer = answer % 10007;

	cout << answer;
}