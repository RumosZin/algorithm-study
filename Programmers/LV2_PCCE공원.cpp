#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 깔 수 있는 가장 큰 돗자리, 정사각형
// Brute Force 

// 놓친 케이스  (처음 30)
// 1 : 아예 돗자리를 깔 수 없는 경우 40
// 2 : 돗자리와 정사각형 크기 같은 경우 75
// 3 : 질문하기 보니까 예시 잘못 나옴
// 4 : 여러 테스트 케이스 추가해봐도 문제가 뭔지 모르겠다... BF로 풀면 안되고 DP로 풀어야 하나보다..

bool cmp (int a, int b) {
    if(a < b) return false;
    else return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    sort(mats.begin(), mats.end());
    
    int width = park[0].size();
    int height = park.size();
    int max_dotjary = 0;
    
    // 파크 칸마다 각 칸을 왼쪽 위 정사각형의 점이라고 했을 때
    // 가장 큰 정사각형의 크기 구하기
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(park[i][j] != "-1") continue;
            
            int width_max = width - j;
            int height_max = height - i;
            cout << "\t" << width_max << " " << height_max << "\n";
            
            // 시작 점에서 가로 최대
            for(int k = i; k < height; k++) {
                for(int l = j; l < width; l++) {
                    if(park[k][l] != "-1") {
                        
                        if(width_max > l - j && l != j) width_max = l - j;
                        if(i == 4 && j == 5) {
                            cout << k << " " << l << width_max << "\n";
                        }
                    }
                    if(park[k][j] != "-1") {
                        if(height_max > k - i && k != i) height_max = k - i;
                    }
                }
            }
            
            int max_dot = min(width_max, height_max);  
            cout << "(" << i << ", " << j << ")" << width_max << " " << height_max << "\n";
            if(max_dotjary < max_dot) max_dotjary = max_dot;
        }
    }
    
    cout << "\t" << max_dotjary << "\n";
    
    for(int i = 0; i < mats.size(); i++) {
        if(mats[i] <= max_dotjary) {
            answer = mats[i];
        }
    }
    
    if(max_dotjary == 0 || answer == 0) answer = -1;
    
    return answer;
}