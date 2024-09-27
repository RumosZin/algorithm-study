#include <iostream>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// 8:27 - 8:50

int find_max(int a, int b, int c) {
    priority_queue<int> pq;
    pq.push(a); pq.push(b); pq.push(c);
    
    return pq.top();
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    vector<vector<int>> dp(land.size(), vector<int>(4, 0));

    for(int i = 0; i < 4; i++) dp[0][i] = land[0][i];
        
    
    for(int i = 1; i < land.size(); i++) {
        dp[i][0] = find_max(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]) + land[i][0];
        dp[i][1] = find_max(dp[i - 1][0], dp[i - 1][2], dp[i - 1][3]) + land[i][1];
        dp[i][2] = find_max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][3]) + land[i][2];
        dp[i][3] = find_max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) + land[i][3];
    }
    
    for(int i = 0; i < 4; i++)
        if(dp[land.size() - 1][i] > answer) answer = dp[land.size() - 1][i];
            
    return answer;
}