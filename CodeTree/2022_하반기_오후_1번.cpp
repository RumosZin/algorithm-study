#include <iostream>
#include <queue>

using namespace std;

int n, m;
int curr_t; // 현재 시간

int grid[15][15]; // 격자
pair<int, int> cvs[30]; // 편의점 목록
pair<int, int> people[30]; // 사람들의 위치

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int step[15][15]; // 최단 거리 결과 기록
bool visited[15][15]; // 방문 기록

// 격자 내에 있는 좌표인지 판단
bool inRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

// 그곳으로 이동 가능한지 판단
bool canGo(int x, int y) {
    return inRange(x, y) && !visited[x][y] && grid[x][y] != 2;
}

void bfs(pair<int, int> pos) {
    // visited, step 초기화
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n ; j++) {
            visited[i][j] = false;
            step[i][j] = 0;
        }
    }

    // 초기 위치
    queue<pair<int, int>> q;
    int sx = pos.first;
    int sy = pos.second;

    q.push({sx, sy});
    visited[sx][sy] = true;
    step[sx][sy] = 0;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(canGo(nx, ny)) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                step[nx][ny] = step[x][y] + 1;
            }
        }
    }
}

void simulate() {
    // 1. 격자에 있는 사람들만 편의점 쪽으로 한 칸 이동
    for(int i = 0; i < m; i++) {
        if(people[i] == make_pair(-1, -1) || people[i] == cvs[i]) continue;

        // 편의점에서 시작해서 다른 모든 칸으로 가는 최단 거리를 구한다.
        // 굳이 distance를 구하지 않는 이유는, 중간에 막힌 칸들은 이동할 수 없기 때문이다!
        bfs(cvs[i]); 

        int px = people[i].first;
        int py = people[i].second;

        int min_dist = 98765;
        int min_x = -1;
        int min_y = -1;
        for(int d = 0; d < 4;  d++) {
            int nx = px + dx[d];
            int ny = py + dy[d];

            if(inRange(nx, ny) && visited[nx][ny] && min_dist > step[nx][ny]) {
                min_dist = step[nx][ny];
                min_x = nx;
                min_y = ny;
            }
        }

        // 편의점과 가까워지는 쪽으로, 우선순위가 높은 위치로 이동
        people[i] = {min_x, min_y};
    }

    // 2. 편의점에 도착한 사람에 한하여 앞으로 이동 불가능하다는 표시로 2 체크
    for(int i = 0; i < m; i++) {
        if(people[i] == cvs[i]) {
            int px = people[i].first;
            int py = people[i].second;
            grid[px][py] = 2;
        }
    }

    // 3. 현재 시간 curr_t에 대해서 curr_t <= m이면 t번 사람이 베이스 캠프로 이동
    if(curr_t > m) return;

    // 3-1. 편의점으로부터 가장 가까운 베이스 캠프를 고르기 위해서 편의점 시작 bfs 수행
    bfs(cvs[curr_t - 1]);

    // 3-2. 편의점에서 가장 가까운 베이스 캠프 선택
    int min_dist = 98765;
    int min_x = -1;
    int min_y = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // 방문 가능한 베이스 캠프 중 가장 가까운 것 찾기
            if(visited[i][j] && grid[i][j] == 1 
                && min_dist > step[i][j]) {
                    min_dist = step[i][j];
                    min_x = i;
                    min_y = j;
                }
        }
    }
    
    // 우선순위가 가장 높은 베이스 캠프로 이동
    people[curr_t - 1] = {min_x, min_y};
    grid[min_x][min_y] = 2; // 베이스 캠프에 방문한 사람이 있다면 이동 불가능
}

// 전부 편의점에 도착하면 끝난다
bool end() {
    // 모든 사람의 위치가 각자 자기가 원하는 편의점의 위치인지 확인
    for(int i = 0; i < m; i++) {
        if(people[i] != cvs[i]) return false;
    }

    return true;
}

int main() {
    // input
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) 
            cin >> grid[i][j];

    for(int i = 0; i < m ; i++) {
        int x, y;
        cin >> x >> y;
        cvs[i] = {x - 1, y - 1};
    }

    // 초기 사람들은 전부 격자 밖에 위치한다.
    for(int i = 0; i < m; i++) people[i] = {-1, -1};
    
    // 1분에 한 번씩 시뮬레이션
    while(1) {
        curr_t++;
        simulate();
        if(end()) break;
    }

    cout << curr_t;
    return 0;
}