#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 8:48 : 20분동안 아이디어를 떠올리지 못함...
// dp[i] : i개의 N으로 만들 수 있는 숫자들!
// dp는 단순히 수를 가지고 있는 것이 아니라, 집합을 가지고 있다

int get_N(int n, int k) {
    int res = n;
    for(int i = 1; i <= k; i++) {
        res = res * 10 + n;
    }
    return res;
}

int solution(int N, int number) {
    if(N == number) return 1;
    int answer = 0;
    
    vector<unordered_set<int>> dp(8);
    dp[0].insert(N); // 한개의 N으로 만들 수 있는 것은 N뿐이다
    
    for(int k = 1; k < 8; k++) {
        dp[k].insert(get_N(N, k));
        
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                if(i + j + 1 != k) continue;
                for(int a : dp[i]) {
                    for(int b : dp[j]) {
                        dp[k].insert(a + b);
                        dp[k].insert(a * b);
                        if(a - b > 0) dp[k].insert(a - b);
                        if(a / b > 0) dp[k].insert(a / b);
                    }
                }
            }
        }
        if(dp[k].find(number) != dp[k].end()) 
            return k + 1;
    }
    
    return -1;
}