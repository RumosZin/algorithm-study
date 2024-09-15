#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    int max_dot = -1;
    int width = park[0].size();
    int height = park.size();
    
    sort(mats.begin(), mats.end());
    
    vector<vector<int>> dp(park.size(), vector<int>(park[0].size(), 0)); // 이 선언 방식 외우기!! 오늘 문제에서 두번째 등장하고 있다
    
    // 빈 잔디가 아닌 경우 dp 0
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(park[i][j] != "-1") dp[i][j] = 0;
            else if(i > 0 && j > 0) {
                    int min_rec = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
                    dp[i][j] = min_rec + 1;
                    if(dp[i][j] > max_dot) max_dot = dp[i][j];                  
            }
            else dp[i][j] = 1;  
            
        }
    }
    
    if(max_dot != -1) {
        for(int i = 0; i < mats.size(); i++) {
            if(mats[i] <= max_dot) answer = mats[i];
        }
    }
    return answer;
}