#include <iostream>
#include <vector>
#include <queue>

using namespace std; // 12:46 - 12:59

// 1,1에서 N, M까지 이동할 때 지나는 최소의 칸 수
int N, M;
vector<vector<int>> arr;
vector<vector<bool>> visited;

typedef struct location {
    int r, c, cnt;
} location;

queue<location> q;
int answer = 0;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main () {
    // input
    cin >> N >> M;
    arr = vector<vector<int>>(N, vector<int>(M));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));

    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < M; j++) {
            arr[i][j] = str[j] - '0';
        }
    }

    // bfs
    q.push({0, 0, 1});
    visited[0][0] = true;

    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int cnt = q.front().cnt;
        q.pop();

        // stop condition
        if(r == N - 1 && c == M - 1) {
            answer = cnt;
            break;
        }

        for(int d = 0; d < 4; d++) {
            int rr = r + dx[d];
            int cc = c + dy[d];

            if(rr < 0 || rr >= N || cc < 0 || cc >= M
            || arr[rr][cc] == 0 || visited[rr][cc]) continue;
            q.push({rr, cc, cnt + 1});
            visited[rr][cc] = true;
        }
    }
    
    cout << answer;

    return 0;
}