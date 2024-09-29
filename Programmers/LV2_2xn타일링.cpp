#include <string>
#include <vector>
#include <bits/stdc++.h>
#define M 1000000007

// 12:21

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<long long> dp(n + 1);
    dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % M;
    }
    
    answer = dp[n];
    return answer;
}