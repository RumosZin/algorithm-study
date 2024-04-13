#include <iostream>
#include <queue>

using namespace std;

struct INFO {
    int ry, rx, by, bx, count;
};

INFO start;

char map[11][11];

int dy[4] = { -1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int bfs() {
    int visited[10][10][10][10] = {0, }; // ry, rx, by, bx
    queue<INFO> q;
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx];

    int ret = -1;

    while(!q.empty()) {
        INFO current = q.front();
        q.pop();

        if(current.count > 10) break;
        if(map[current.ry][current.rx] == 'O' && map[current.by][current.bx] != 'O') {
            ret = current.count;
            break;
        }

        for(int d = 0; d < 4; d++) {
            int next_ry = current.ry;
            int next_rx = current.rx;
            int next_by = current.by;
            int next_bx = current.bx;

            // RED
            while(1) {
                if(map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O') {
                    next_ry += dy[d];
                    next_rx += dx[d];
                }
                else {
                    if(map[next_ry][next_rx] == '#') {
                    next_ry -= dy[d];
                    next_rx -= dx[d];                      

                    }
                    break;
                }

            }
            
            // BLUE
            while(1) {
                if(map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O') {
                    next_by += dy[d];
                    next_bx += dx[d];
                }
                else {
                    if(map[next_by][next_bx] == '#') {
                    next_by -= dy[d];
                    next_bx -= dx[d];                      

                    }
                    break;
                }

            }
        }

    }

    return ret;

}

int main() {

    // input
    int N, M;
    cin >> N >> M;
    for(int y = 0; y < N; y++) {
        string input;
        cin >> input;
        for(int x = 0; x < M; x++) {
            map[y][x] = input[j];

            if(map[y][x] == 'R') {
                start.ry = y; start.rx = x;
            }
            if(map[y][x] == 'B') {
                start.by = y; start.bx = x;
            }
        }
    }

    start.count = 0;

    cout <<  bfs();

    return 0;
}