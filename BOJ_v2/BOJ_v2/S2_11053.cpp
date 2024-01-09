#include <iostream>
#include <vector>

using namespace std;

int dp[1001][2];
vector<int> input;


int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		input.push_back(num);
	}

	for (int i = 0; i < N; i++) {
		int max_length = 0;
		for (int j = 0; j < i; j++) {
			if (dp[j][0] >= input[i]) continue;
			else {
				//cout << dp[j][0] << "\n";
				if (max_length <= dp[j][1]) {
					max_length = dp[j][1];
					//cout << "\t" << max_length;
				}
			}
		}
		dp[i][0] = input[i];
		dp[i][1] = max_length + 1;

		//cout << dp[i][0] << " " << dp[i][1] << "s\n";
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		if (answer <= dp[i][1]) answer = dp[i][1];

	}
	cout << answer;
}