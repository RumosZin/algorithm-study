#include <string>
#include <vector>

using namespace std;

// 11:23 - 11:27

int solution(int n) {
    int answer = 0;
    
    vector<int> dp;
    dp.push_back(1); dp.push_back(1);
    int cnt = dp.size();
    
    int idx = 2;
    while(true) {
        dp.push_back((dp[idx - 1] + dp[idx - 2]) % 1234567);
        idx++; cnt++;
        if(cnt == n) {
            answer = dp[dp.size() - 1]; break;
        }
    }
    
    return answer;
}