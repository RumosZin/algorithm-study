#include <iostream>
#include <vector>

using namespace std;

int N; // 수열의 크기
vector<int> sequence;
vector<int> left_dp;
vector<int> right_dp;

void LIS() {
    for(int i = 0; i < N; i++) {
        left_dp[i] = 1; // me
        for(int j = 0; j < i; j++) {
            if(sequence[i] > sequence[j] && left_dp[i] < left_dp[j] + 1) 
                left_dp[i] = left_dp[j] + 1;
        }
    }
}

void LDS() {
    for(int i = N - 1; i >= 0; i--) {
        right_dp[i] = 1;
        for(int j = N - 1; j > i; j--) {
            if(sequence[i] > sequence[j] && right_dp[i] < right_dp[j] + 1) 
                    right_dp[i] = right_dp[j] + 1;
        }
    }
}

int main() {
    // input
    cin >> N; 
    sequence.resize(N); left_dp.resize(N); right_dp.resize(N);
    for(int i = 0; i < N; i++) cin >> sequence[i];

    // Longest Increasing/Decreasing Count
    LIS(); LDS();

    // Find Largest value
    int max_value = 0;
    for(int i = 0; i < N; i++) {
        if(max_value < left_dp[i] + right_dp[i]) max_value = left_dp[i] + right_dp[i];
    }

    // answer
    cout << max_value - 1; return 0;
}