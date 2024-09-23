#include <string>
#include <vector>
#include <bits/stdc++.h>

// 3:37 - 4:02
using namespace std;

vector<bool> visited; 
vector<vector<int>> dun;
int answer = -1;
int v_size = 0;

void dfs(int k, int count) {
    answer = max(answer, count);
    
    for(int i = 0; i < v_size; i++) {
        if(dun[i][0] <= k && !visited[i]) {
            visited[i] = true; 
            dfs(k - dun[i][1], count + 1);
            visited[i] = false; 
        }
    }
    
}

int solution(int k, vector<vector<int>> dungeons) {
    v_size = dungeons.size();
    dun = dungeons;
    visited.resize(v_size);
    
    dfs(k, 0); // 현재까지의 피로도, 현재까지 방문한 던전의 개수
    
    return answer;
}