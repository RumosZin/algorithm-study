#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
    // input
    cin >> N; 
    vector<int> arr(N);
    for(int i = 0; i < N; i++) 
        cin >> arr[i];

    // dp
    vector<vector<int>> dp(N, vector<int>(2, 0));

    if(N == 1) {
        cout << arr[0];
        return 0;
    }
    if(N == 2) {
        cout << arr[0] + arr[1];
        return 0;
    }

    dp[0][0] = arr[0]; dp[0][1] = arr[0];
    dp[1][0] = arr[1]; dp[1][1] = arr[0] + arr[1];

    for(int i = 2; i < N; i++) {
        dp[i][0] = max(dp[i - 2][1], dp[i - 2][0]) + arr[i];
        dp[i][1] = dp[i - 1][0] + arr[i];
    }
    // for(int i = 0; i < N; i++) {
    //     cout << dp[i][0] << " " << dp[i][1] << "\n";
    // }

    cout << max(dp[N - 1][0], dp[N - 1][1]);
    return 0;
}