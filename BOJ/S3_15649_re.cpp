#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<bool> visited;
vector<int> arr;
// 1:57

void backtracking(int cnt) {
    if(cnt == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i = 1; i <= N; i++) {
        if(visited[i]) continue;

        visited[i] = true;
        arr[cnt] = i;
        backtracking(cnt + 1);
        visited[i] = false;
    }

    return ;
}

int main() {
    // input
    cin >> N >> M;
    // 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

    visited.resize(N + 1, false);
    arr.resize(N + 1);
    
    backtracking(0); // 현재까지 0개 담음

    return 0;
}