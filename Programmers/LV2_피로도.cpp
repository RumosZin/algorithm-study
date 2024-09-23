#include <string>
#include <vector>
#include <bits/stdc++.h>

// 3:37 - 4:02
using namespace std;

vector<bool> visited; 
vector<vector<int>> dun;
int answer = -1;
int v_size = 0;

void dfs(int d, int k, int count) {
    visited[d] = true; count++;
    
    for(int i = 0; i < v_size; i++) {
        if(visited[i]) continue;
        if(dun[i][0] <= k && !visited[i]) dfs(i, k - dun[i][1], count);
        else { continue; }
    }
    visited[d] = false; answer = max(answer, count);
}

int solution(int k, vector<vector<int>> dungeons) {
    v_size = dungeons.size();
    dun = dungeons;
    visited.resize(v_size); 
    
    for(int i = 0; i < dungeons.size(); i++) { 
        dfs(i, k - dungeons[i][1], 0); // 시작, 현재까지 피로도, 현재까지 방문한 던전의 개수
    }
    
    return answer;
}