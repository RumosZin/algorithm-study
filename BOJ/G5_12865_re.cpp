#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<pair<int, int>> vv; // 무게, 가치

int main() {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;
        vv.push_back({w, v});
    }

    // [보석 개수 + 1][배낭 무게 + 1] 배열 생성
    vector<vector<int>> dp(vv.size() + 1, vector<int>(K + 1));
    
    // 각 보석을 넣을지 말지, 무게를 측정하면서 계산! DP
    for(int i = 1; i <= N; i++) {
        int weight = vv[i - 1].first;
        int cost = vv[i - 1].second;
        for(int j = 1; j <= K; j++) {
            // 현재 짐을 담을 수 있을 때
            // 현재 짐을 넣지 않는 것 / 넣는 것 중 최댓값 선정
            if(weight <= j) 
                dp[i][j] = max(dp[i - 1][j - weight] + cost, dp[i - 1][j]);
            
            // 현재 짐을 담을 수 없을 때
            // 바로 윗 칸의 값을 가져온다
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    cout << dp[N][K];
    return 0;
}