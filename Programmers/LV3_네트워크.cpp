#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// 5:53

vector<vector<int>> coms;
vector<bool> visited;
int nodes;

void dfs(int node) {
    visited[node] = true;
    
    for(int j = 0; j < nodes; j++) {
        if(visited[j] || coms[node][j] == 0) continue;
        dfs(j);
    } 

    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    coms = computers;
    
    int r = computers.size(); 
    int c = computers[0].size();
    nodes = r;
    
    visited = vector<bool>(r, false);
    
    for(int i = 0; i < r; i++) {
        if(visited[i]) continue;
        answer++;
        dfs(i);
    }
    return answer;
}