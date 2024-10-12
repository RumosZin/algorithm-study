#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dx2[9] = {0, 0, 0, -1, -1, -1, 1, 1, 1};
int dy2[9] = {0, -1, 1, 0, -1, 1, 0, -1, 1};

int n, m, k;
int turn;

int board[10][10]; // 현재 포탑들이 가진 힘
int rec[10][10]; 

bool visited[10][10]; // 레이저 공격에서 방문 여부
int back_x[10][10]; // 경로 방향
int back_y[10][10];
bool active[10][10]; // 공격과 무관했는지 여부

struct tower {
    int x, y, t, p;
};

vector<tower> towers;

bool cmp(tower a, tower b) {
    if(a.p != b.p) return a.p < b.p;
    if(a.t != b.t) return a.t > b.t;
    if(a.x + a.y != b.x + b.y) return a.x + a.y > b.x + b.y;
    return a.y > b.y;
}

// 전처리
void init() {
    turn++;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = false;
            active[i][j] = false;
        }
    }
}

// 우선순위에 맞게 공격포탑, 피공격포탑 정하기
void awake() {
    sort(towers.begin(), towers.end(), cmp);

    tower attack = towers[0];
    int x = attack.x;
    int y = attack.y;

    // 보드에 값 추가
    // 언제 마지막으로 공격했는지 현재 기록 추가
    // 타워 정보 업데이트
    board[x][y] += n + m;
    rec[x][y] = turn;
    attack.p = board[x][y];
    attack.t = rec[x][y];
    active[x][y] = true; // 공격과 관련 있음

    towers[0] = attack;
}

bool laserAttack() {
    // 가장 앞에 있는 포탑이 공격자
    tower attacker = towers[0];
    int sx = attacker.x;
    int sy = attacker.y;
    int sp = attacker.p;

    tower defenser = towers[towers.size() - 1];
    int ex = defenser.x;
    int ey = defenser.y;

    // bfs로 최단경로!
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    // 도달 가능 여부 
    bool canAttack = false;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // stop condition
        if(x == ex && y == ey) {
            canAttack = true;
            break;
        }

        for(int d = 0; d < 4; d++) {
            int nx = (x + dx[d] + n) % n;
            int ny = (y + dy[d] + m) % m;

            if(visited[nx][ny] || board[nx][ny] == 0) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
            back_x[nx][ny] = x;
            back_y[nx][ny] = y;
        }
    }

    if(canAttack) {
        // 도달 가능하니까 공격
        board[ex][ey] -= sp;
        if(board[ex][ey] < 0) board[ex][ey] = 0;
        active[ex][ey] = true;

        // 기존 경로를 역추적해서 
        // 경로의 모든 포탑에 pow/2만큼의 공격 진행
        int cx = back_x[ex][ey];
        int cy = back_y[ex][ey];

        while(!(cx == sx && cy == sy)) {
            board[cx][cy] -= sp / 2;
            if(board[cx][cy] < 0) board[cx][cy] = 0;
            active[cx][cy] = true;

            int ncx = back_x[cx][cy];
            int ncy = back_y[cx][cy];
            cx = ncx;
            cy = ncy;
        }
    }

    return canAttack;
}

void bombAttack() {
    // 가장 앞에 있는 포탑이 공격자
    tower attacker = towers[0];
    int sx = attacker.x;
    int sy = attacker.y;
    int sp = attacker.p;

    tower defenser = towers[towers.size() - 1];
    int ex = defenser.x;
    int ey = defenser.y;

    // 3x3 범위를 탐색하면서 공격 진행
    for(int d = 0; d < 9; d++) {
        int nx = (ex + dx2[d] + n) % n;
        int ny = (ey + dy2[d] + m) % m;

        if(nx == sx && ny == sy) continue; // 자기 자신일 경우 넘어가기
        if(nx == ex && ny == ey) {
            board[nx][ny] -= sp;
            if(board[nx][ny] < 0) board[nx][ny] = 0;
            active[nx][ny] = true;
        }
        else {
            board[nx][ny] -= sp / 2;
            if(board[nx][ny] < 0) board[nx][ny] = 0;
            active[nx][ny] = true;
        }
    }
}

void executor() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(active[i][j] || board[i][j] == 0) continue;
            board[i][j]++;
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    while(k--) {
        // 살아있는 포탑 카운트
        towers.clear();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j]) {
                    tower tw;
                    tw.x = i;
                    tw.y = j;
                    tw.t = rec[i][j];
                    tw.p = board[i][j];

                    towers.push_back(tw);
                }
            }
        }

        // 포탑이 1개 이하이면 종료
        if(towers.size() <= 1) break;

        init();
        awake(); 

        bool attacked = laserAttack();
        if(!attacked) bombAttack();

        // 포탑의 힘 증가
        executor();
    }

    int answer = 0;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            answer = max(answer, board[i][j]);

    cout << answer;

    return 0;
}