#include <iostream>

using namespace std;

int n, m, k;
int board[11][11]; // 미로의 상태
int next_board[11][11]; // 회전의 구현을 쉽게 하기 위해서 2차원 배열 재선언

pair<int, int> participants[11]; // 참가자 위치 정보
pair<int, int> exits; // 출구의 위치 정보

int answer = 0; // 모든 참가자들의 이동 거리의 합
int sx, sy, square_size; // 회전해야 하는 최소 정사각형

// 모든 사람들을 미로 내에서 이동
void move() {
    for(int i = 1; i <= m; i++) {
        // 출구에 있는 경우 스킵
        if(participants[i].first == exits.first 
            && participants[i].second == exits.second) continue;

        // 행이 다른 경우 행을 이동 (상하가 먼저라고 했으므로)
        if(participants[i].first != exits.first) {
            int nx = participants[i].first;
            int ny = participants[i].second;

            if(exits.first > nx) nx++; // 가까운 쪽으로 이동하도록 nx 조정
            else nx--;

            // 벽이 없으면 행 이동
            // 행 이동하고 바로 다음 참가자 : 행 우선, 그 다음 열
            if(board[nx][ny] == 0) {
                participants[i] = {nx, ny};
                answer++; // 가까워지는 방향으로 한 칸만 이동
                continue;
            }
        }

        // 행이 다를 때 : 행이 같도록 움직이는 것 우선
        // 행이 같을 때 : 행 다음 열이 작은 것 우선
        if(participants[i].second != exits.second) {
            int nx = participants[i].first;
            int ny = participants[i].second;

            if(exits.second > ny) ny++;
            else ny--;

            // 벽이 없으면 이동 가능
            if(board[nx][ny] == 0) {
                participants[i] = {nx, ny};
                answer++;
                continue;
            }
        }
    }
}

// 한 명 이상의 참가자와 출구를 포함한 가장 작은 정사각형 찾기
void square() {
    // 가장 작은 정사각형부터 만들기
    for(int sz = 2; sz <= n; sz++) {
        // ㄱ좌표가 작은 것부터
        for(int x1 = 1; x1 <= n - sz + 1; x1++) {
            for(int y1 = 1; y1 <= n - sz + 1; y1++) {
                int x2 = x1 + sz - 1; // (x1, y1) 시작점
                int y2 = y1 + sz - 1; // (x2, y2) 끝점

                // 이 정사각형 안에 출구가 있는지 판단
                if(!(x1 <= exits.first && exits.first <= x2
                    && y1 <= exits.second && exits.second <= y2)) continue;
                
                // 출구가 있다면, 참가자 한 명 이상 있는지 확인
                bool isIn = false;
                for(int i = 1; i <= m; i++) {
                    if(x1 <= participants[i].first 
                        && participants[i].first <= x2
                        && y1 <= participants[i].second
                        && participants[i].second <= y2) {
                            if(!(participants[i].first == exits.first
                            && participants[i].second == exits.second)) isIn = true;
                        }
                }

                if(isIn) {
                    sx = x1; // 시작 좌표 
                    sy = y1; 
                    square_size = sz;

                    return;
                }
            }
        }
    }
}

// 정사각형 미로 회전
void squareRotate() {
    // 벽돌들 1 감소하고 시작
    for(int x = sx; x < sx + square_size; x++) {
        for(int y = sy; y < sy + square_size; y++) {
            if(board[x][y]) board[x][y]--; // 0보다 큰 경우에만 감소
        }
    }

    // 정사각형을 시계방향으로 90도 회전
    for(int x = sx; x < sx + square_size; x++) {
        for(int y = sy; y < sy + square_size; y++) {
            // 상대좌표 계산 (sx, sy) - (0, 0)
            int ox = x - sx;
            int oy = y - sy;

            // (x, y) -> (y, square_size - 1 - x)
            int rx = oy;
            int ry = square_size - ox - 1;

            // 좌표에 sx, sy를 더해서 담기
            next_board[sx + rx][sy + ry] = board[x][y];
        }
    }

    // next_board를 현재 board에 옮기기
    for(int x = sx; x < sx + square_size; x++) {
        for(int y = sy; y < sy + square_size; y++) {
            board[x][y] = next_board[x][y];
        }
    }
}

// 참가자들, 출구를 회전시키기
void participantsRotate() {
    // 참가자 회전
    for(int i = 1; i <= m; i++) {
        int x = participants[i].first;
        int y = participants[i].second;

        // 정사각형 안에 있는 것만 회전해요~
        if(sx <= x && x < sx + square_size && sy <= y && y < sy + square_size) {
            // 상대 좌표로 변환 (sx, sy)-(0, 0)
            int ox = x - sx;
            int oy = y - sy;

            // 변환된 상태에서 (x, y)-(y, square_size - 1 - x)
            int rx = oy;
            int ry = square_size - 1 - ox;

            // 다시 더해서 옮기기
            participants[i] = {sx + rx, sy + ry};
        }
    }

    // 출구 회전
    int x = exits.first;
    int y = exits.second;
    if(sx <= x && x < sx + square_size && sy <= y && y < sy + square_size) {
        int ox = x - sx;
        int oy = y - sy;
        
        int rx = oy;
        int ry = square_size - 1 - ox;

        exits = {sx + rx, sy + ry};
    }

}

int main() {
    // input
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 1; i <= m; i++) {
        cin >> participants[i].first;
        cin >> participants[i].second;
    }

    cin >> exits.first >> exits.second;

    while(k--) {
        move();

        bool isEscaped = true;
        for(int i = 1; i <= m; i++) {
            if(!(participants[i].first == exits.first 
                && participants[i].second == exits.second)) isEscaped = false;
        }

        // 모든 사람이 탈출했으면 종료
        if(isEscaped) break;

        square();
        squareRotate();
        participantsRotate();
    }

    cout << answer << "\n";
    cout << exits.first << " " << exits.second;

    return 0;
}