#include <iostream>
#include <vector>
#include <queue>

using namespace std; // 1:15 - 1:41

int N, M;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dz[2] = {1, -1};

// 1 : 익은 토마토 / 0 : 익지 않은 토마토 / -1 : 토마토 없음
vector<vector<int>> arr;
vector<vector<bool>> visited;

typedef struct location {
    int r, c, cnt;
} location;

queue<location> q;
int answer = 0;

int main() {
    // input
     cin >> M >> N;
     arr = vector<vector<int>>(N, vector<int>(M));

     for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                q.push({i, j, 0});
            }
        }
     }

    // bfs
     while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int cnt = q.front().cnt;
        q.pop();

        if(cnt > answer) answer = cnt;

        for(int d = 0; d < 4; d++) {
            int rr = r + dx[d];
            int cc = c + dy[d];
            if(rr < 0 || rr >= N || cc < 0 || cc >= M) continue;
            if(arr[rr][cc] != 0) continue;

            q.push({rr, cc, cnt + 1});
            arr[rr][cc] = cnt + 1;
        }
     }

    bool find = true;
     for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(arr[i][j] == 0) {
                find = false;
                break;
            }
        }
     }

    if(find) cout << answer;
    else cout << -1;

     return 0;
}