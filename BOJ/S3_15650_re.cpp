#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<bool> visited;

void backtracking(int idx, int cnt) {
    // cout << idx << " " << cnt << "\n";
    if(cnt == M) {
        for(int i = 0; i < 9; i++) {
            if(visited[i]) cout << i << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = idx + 1; i <= N; i++) {
        visited[i] = true;
        backtracking(i, cnt + 1);
        visited[i] = false;
    }
}

int main() {
    // input
    cin >> N >> M;
    visited.resize(N + 1, false);

    backtracking(0, 0); // 현재 인덱스, 현재 카운트

    return 0;
}