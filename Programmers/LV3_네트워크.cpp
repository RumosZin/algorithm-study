#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// 5:53 - 6:11

vector<vector<int>> coms;
vector<vector<bool>> visited;
int nodes;

void dfs(int start, int next) {
    visited[start][next] = true;  
    visited[next][start] = true;
    
    // next 노드에 대해서, next와 연결된 다음 노드들도 방문 체크를 한다
    // 이때 dfs를 계산할 때는 시작 점이 고정이기 때문에 이중 for문을 사용하지 않는다
    for(int j = 0; j < nodes; j++) {
        if(visited[next][j] || visited[j][next] || coms[next][j] == 0) continue;
        dfs(next, j);
    } 

    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    coms = computers;
    
    int r = computers.size(); nodes = r;
    int c = computers[0].size();
    
    visited = vector<vector<bool>>(r, vector<bool>(c, false));
    
    // 이중 for문을 돌면서 방문하지 않은 노드에 대해서 탐색한다.
    // computers가 이차원 배열로 선언되어 있기도 하고, 단순 쌍으로 주어졌을 때에도 
    // 이차원 배열을 만들어서 처리 가능하다.
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(visited[i][j] || visited[j][i] || coms[i][j] == 0) continue;
            dfs(i, j); // start, next
            answer++;
        } 
    }
    return answer;
}