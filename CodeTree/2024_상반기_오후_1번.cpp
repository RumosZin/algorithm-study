#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std; // 2:43 - 4:07 1차 구현
// 4:20 - 4:28 디버깅 51% 런타임 에러 (예제는 다 맞음)
// 4:37 r, c 범위 설정
// 4:46 위치 판단 K 범위 틀린 것 바로 잡기!

int R, C, K;
int forest[75][72]; 
int answer = 0;
map<int, int> rem; // rem[k] : k의 출구 방향
vector<pair<int, int>> rem_location[1001]; // rem_loation[k] : k의 중심 위치

// 북, 동, 남, 서
int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, 1, 0, -1};

bool south(int r, int c) { 
    // 범위 체크
    if(r + 2 > R + 2 || r + 1 > R + 2 || c - 1 < 1 || c + 1 > C ) return false;

    if(forest[r + 1][c - 1] == 0 && forest[r + 1][c + 1] == 0
        && forest[r + 2][c] == 0) return true;
    else return false;
}

bool west(int r, int c) {
    // 범위 체크
    if(r - 1 < 0 || r + 1 > R + 2 || r + 2 > R + 2
        || c - 2 < 1 || c - 1 < 1) return false;

    if(forest[r - 1][c - 1] == 0 && forest[r][c - 2] == 0
        && forest[r + 1][c - 1] == 0
        && forest[r + 1][c - 2] == 0 && forest[r + 2][c - 1] == 0) return true;
    else return false;
}

bool east(int r, int c) {
    // 범위 체크
    if(r - 1 < 0 || r + 1 > R + 2 || r + 2 > R + 2
        || c + 2 > C || c + 1 > C) return false;

    if(forest[r - 1][c + 1] == 0 && forest[r][c + 2] == 0
        && forest[r + 1][c + 1] == 0
        && forest[r + 1][c + 2] == 0 && forest[r + 2][c + 1] == 0) return true;
    else return false;
}

void stop(int r, int c, int dir, int n) {
    // 숲에서 위치 기록
    forest[r][c] = n;
    for(int d = 0; d < 4; d++) 
        forest[r + dx[d]][c + dy[d]] = n;
    
    // 각 골렘의 출구 기록
    rem[n] = dir;
    rem_location[n].push_back({r, c});
}

// c, d로 들어온 n 정령의 위치 찾기
vector<int> move(int r, int c, int d, int n) {
    while(1) {
        // 1. 남쪽으로 한 칸 내려가기
        if(south(r, c)) {
            r += 1;
            continue;
        }
        // 2. 1번이 안되면 서쪽 방향으로 회전하며 내려가기
        else if(west(r, c)) {
            r += 1;
            c -= 1;
            d = (d + 3) % 4;
            continue;
        }
        // 3. 1번과 2번이 안되면 동쪽 방향으로 회전하며 내려가기
        else if(east(r, c)) {
            r += 1;
            c += 1;
            d = (d + 5) % 4;
            continue;
        }
        // 4. 모두 다 안되면 위치를 기록하고 반환하기
        else {
            stop(r, c, d, n);
            break;
        }
    }

    return {r, c, d}; // 최종 위치 반환
}

bool forested_check(int r, int c, int d) {
    if(r > 3) return true;
    else return false; 
}

void forest_reset() {
    for(int i = 0; i < R + 4; i++) {
        for(int j = 0; j < C + 2; j++) {
            forest[i][j] = 0;
        }
    }
}

int entrance(vector<int> l) {
    int value = 0;

    queue<int> q;
    set<int> s;
    q.push(forest[l[0]][l[1]]);
    s.insert(forest[l[0]][l[1]]);

    while(!q.empty()) { // 현재 위치에서 가장 아래로 가는 것 찾기
        int cur_rem = q.front();
        int cur_r = rem_location[cur_rem][0].first; // 현재 골렘 위치
        int cur_c = rem_location[cur_rem][0].second;
        int cur_d = rem[cur_rem];
        q.pop();

        value = max(value, cur_r + 1);

        // 출구와 맞닿은 골렘 확인하기
        int ent_r = cur_r + dx[cur_d];
        int ent_c = cur_c + dy[cur_d];

        for(int d = 0; d < 4; d++) {
            int next_r = ent_r + dx[d];
            int next_c = ent_c + dy[d];

            if(next_r < 0 || next_r > R + 2 || next_c < 1 || next_c > C
                || forest[next_r][next_c] == cur_rem
                || forest[next_r][next_c] == 0
                || s.find(forest[next_r][next_c]) != s.end()) continue;

            q.push(forest[next_r][next_c]);
            s.insert(forest[next_r][next_c]);
        }
    }
    
    return value - 2;
}

int main() {
    // input
    cin >> R >> C >> K;

    // move to forest && find entrance
    for(int i = 1; i <= K; i++) {
        int col, dir;
        cin >> col >> dir;

        vector<int> location = move(1, col, dir, i); 

        if(forested_check(location[0], location[1], location[2])) 
            answer += entrance(location); 
        else forest_reset();
    }

    cout << answer;
    
    return 0;
}