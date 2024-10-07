#include <iostream>
#include <vector>

using namespace std; // 5:20

int T;
int N;

int main() {
    // input
    cin >> T;

    for(int t = 0; t < T; t++) {
        cin >> N;
        vector<int> dp(N + 1, 0);

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i = 4; i <= N; i++) {
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
        }

        cout << dp[N] << "\n";
        dp.clear();
    }
    
    return 0;
}