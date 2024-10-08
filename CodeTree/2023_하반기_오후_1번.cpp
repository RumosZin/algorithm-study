#include <iostream>

using namespace std;

#define MAX_N 51 // 게임판 크기 최대
#define MAX_P 31 // 산타 인원 최대

int n, m, p, c, d; 
int points[MAX_P];
pair<int, int> pos[MAX_P]; // pos[k] : k의 위치 (행, 열)
pair<int, int> rudolf; // 루돌프의 위치 (행, 열)

int board[MAX_N][MAX_N];
bool is_live[MAX_P]; // is_live[k] : k의 죽음 여부
int stun[MAX_P]; // stun[k] : k의 기절 날

// 산타의 이동 상우하좌
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1}; 

// (x, y)가 보드 내에 있는 좌표인지 확인
bool is_inrange(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

// 거리 
int distance(int r1, int c1, int r2, int c2) {
    return (r1 - r2) * (r1 - r2) + (c1 - c2) * (c1 - c2);
}

int main() {
    // 입력
    cin >> n >> m >> p >> c >> d;
    cin >> rudolf.first >> rudolf.second;
    board[rudolf.first][rudolf.second] = -1;

    // 산타의 위치 표시
    for(int i = 1; i <= p; i++) {
        int id;
        cin >> id;
        cin >> pos[id].first >> pos[id].second;
        board[pos[id].first][pos[id].second] = id; // 산타의 위치 보드에 표시
        is_live[id] = true; 
    }

    // 턴 게임 시작
    for(int t = 1; t <= m; t++) {
        int closestX = 10000, closestY = 10000, closestIdx = 0;

        // 살아 있는 산타 중에 가장 가까운 산타
        for(int i = 1; i <= p; i++) {
            if(!is_live[i]) continue; // 기절한 산타에게 돌진할 수 있다

            // 거리, 행, 열
            pair<int, pair<int, int>> currentBest = {
                distance(closestX, closestY, rudolf.first, rudolf.second),
                {-closestX, -closestY}
            };

            pair<int, pair<int, int>> currentValue = {
                distance(pos[i].first, pos[i].second, rudolf.first, rudolf.second),
                {-pos[i].first, -pos[i].second}
            };

            if(currentValue < currentBest) {
                closestX = pos[i].first;
                closestY = pos[i].second;
                closestIdx = i;
            }
        }

        // 가장 가까운 산타 방향으로 루돌프 이동 
        // x, y 방향이 8개인데 다 따지지 않고, 가까워지는 쪽으로 x, y를 각각 구한다
        if(closestIdx) {
            pair<int, int> prevRudolf = rudolf;
            int moveX = 0;
            if(closestX > rudolf.first) moveX = 1;
            else if(closestX < rudolf.first) moveX = -1;

            int moveY = 0;
            if(closestY > rudolf.second) moveY = 1;
            else if(closestY < rudolf.second) moveY = -1;

            rudolf.first += moveX;
            rudolf.second += moveY;
            board[prevRudolf.first][prevRudolf.second] = 0;

            // 루돌프의 이동으로 충돌한 경우 산타 이동시키기
            if(rudolf.first == closestX && rudolf.second == closestY) {
                int firstX = closestX + moveX * c;
                int firstY = closestY + moveY * c;
                int lastX = firstX;
                int lastY = firstY;

                stun[closestIdx] = t + 1; // 기절

                // 루돌프 충돌해온 방향으로 맨 끝 위치를 확인하고자 함
                while(is_inrange(lastX, lastY) && board[lastX][lastY] > 0) {
                    lastX += moveX;
                    lastY += moveY;
                }

                // 가장 마지막 위치에서 시작해서 순차적으로 한칸씩 이동
                while(!(lastX == firstX && lastY == firstY)) {
                    int beforeX = lastX - moveX;
                    int beforeY = lastY - moveY;

                    if(!is_inrange(beforeX, beforeY)) break;

                    int idx = board[beforeX][beforeY];

                    if(!is_inrange(lastX, lastY)) {
                        is_live[idx] = false;
                    }
                    else {
                        board[lastX][lastY] = board[beforeX][beforeY];
                        pos[idx] = {lastX, lastY};
                    }

                    lastX = beforeX;
                    lastY = beforeY;
                }

                // 점수 업데이트
                points[closestIdx] += c;
                pos[closestIdx] = {firstX, firstY};

                if(is_inrange(firstX, firstY)) board[firstX][firstY] = closestIdx;
                else is_live[closestIdx] = false;
            }
        }

        // 루돌프의 위치 업데이트
        board[rudolf.first][rudolf.second] = -1;

        // 산타 이동
        for(int i = 1; i <= p; i++) {
            if(!is_live[i] || stun[i] >= t) continue;

            int minDist = distance(pos[i].first, pos[i].second, rudolf.first, rudolf.second);
            int minDir = -1;

            for(int dir = 0; dir < 4; dir++) {
                int nx = pos[i].first + dx[dir];
                int ny = pos[i].second + dy[dir];

                if(!is_inrange(nx, ny) || board[nx][ny] > 0) continue;

                int dist = distance(nx, ny, rudolf.first, rudolf.second);
                if(dist < minDist) {
                    minDist = dist;
                    minDir = dir;
                }
            }

            // 이동이 가능하면
            if(minDir != -1) {
                int nx = pos[i].first + dx[minDir];
                int ny = pos[i].second + dy[minDir];

                // 산타의 이동으로 루돌프와 충돌한 경우, 산타를 이동시키고 처리
                if(nx == rudolf.first && ny == rudolf.second) {
                    stun[i] = t + 1;

                    int moveX = -dx[minDir]; // 산타는 반대로 이동한다
                    int moveY = -dy[minDir];

                    int firstX = nx + moveX * d;
                    int firstY = ny + moveY * d;
                    int lastX = firstX;
                    int lastY = firstY;

                    if(d == 1) points[i] += d; // 한칸 밀리는 건 원래 위치니까 연쇄 안해도 됨
                    else {
                        // 해당 방향의 가장 끝 위치 찾기
                        while(is_inrange(lastX, lastY) && board[lastX][lastY] > 0) {
                            lastX += moveX;
                            lastY += moveY;
                        }
                        
                        // 연쇄 충돌의 가장 마지막 지점부터 first까지 오면서 이동
                        while(!(lastX == firstX && lastY == firstY)) {
                            int beforeX = lastX - moveX;
                            int beforeY = lastY - moveY;

                            if(!is_inrange(beforeX, beforeY)) break;

                            int idx = board[beforeX][beforeY];
                            
                            if(!is_inrange(lastX, lastY)) {
                                is_live[idx] = false;
                            }
                            else {
                                board[lastX][lastY] = board[beforeX][beforeY];
                                pos[idx] = {lastX, lastY};
                            }

                            lastX = beforeX;
                            lastY = beforeY;
                        }

                        // 산타 점수 업데이트
                        points[i] += d;
                        board[pos[i].first][pos[i].second] = 0;
                        pos[i] = {firstX, firstY};
                        if(is_inrange(firstX, firstY)) board[firstX][firstY] = i;
                        else is_live[i] = false;
                    }
                }
                // 충돌하지 않는 경우
                else {
                    board[pos[i].first][pos[i].second] = 0;
                    pos[i] = {nx, ny};
                    board[nx][ny] = i;
                }
            }
        }
        // 라운드 끝나고 점수 증가시키기
        for(int i = 1; i <= p; i++) {
            if(is_live[i]) points[i]++;
        }

    }

    // 점수 출력
    for(int i = 1; i <= p; i++) {
        cout << points[i] << " ";
    }

    return 0;
}