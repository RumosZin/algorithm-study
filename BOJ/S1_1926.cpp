#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 12:22
int N, M; // 세로, 가로
vector<vector<int>> arr;
vector<vector<bool>> visited;
vector<int> correct;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

typedef struct loc {
    int r, c;
} loc;

queue<loc> q;
int current_width = 0;

int bfs() {
    int max_cnt = 0;
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        max_cnt++;
        q.pop();

        for(int d = 0; d < 4; d++) {
            int rr = r + dx[d];
            int cc = c + dy[d];

            if(rr < 0 || rr >= N || cc < 0 || cc >= M 
            || visited[rr][cc] || arr[rr][cc] == 0) continue;
            visited[rr][cc] = true;
            q.push({rr, cc});
        }
    }

    return max_cnt;
}

int main() {
    // input
    cin >> N >> M;
    arr = vector<vector<int>>(N, vector<int>(M));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    // bfs
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!visited[i][j] && arr[i][j] == 1) {
                loc l; l.r = i; l.c = j; 
                visited[i][j] = true;
                q.push(l);
                correct.push_back(bfs());
            }
        }
    }

    sort(correct.begin(), correct.end());
    if(correct.size() == 0) cout << 0 << "\n" << 0;
    else cout << correct.size() << "\n" << correct.back();
    
    return 0;
}