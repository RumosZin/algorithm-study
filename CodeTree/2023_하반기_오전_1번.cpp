#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 31
#define MAX_L 41

int l, n, q;
int info[MAX_L][MAX_L];
int bef_k[MAX_N]; // original k : 데미지를 기록해야 하므로 !
int r[MAX_N], c[MAX_N], h[MAX_N], w[MAX_N], k[MAX_N];
int nr[MAX_N], nc[MAX_N];
int dmg[MAX_N];
bool is_moved[MAX_N];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// 움직임을 시도하기
bool tryMove(int idx, int dir) {
    // 초기화한다
    for(int i = 1; i <= n; i++) {
        dmg[i] = 0;
        is_moved[i] = false;
        nr[i] = r[i];
        nc[i] = c[i];
    }

    queue<int> q; // 움직이는 기사
    q.push(idx); // 큐에 넣고
    is_moved[idx] = true; // 움직임 체크

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        nr[x] += dx[dir];
        nc[x] += dy[dir];

        // 경계를 벗어나는지 체크
        if(nr[x] < 1 || nc[x] < 1 
            || nr[x] + h[x] - 1 > l || nc[x] + w[x] - 1 > l) return false;
        
        // 현재 기사가 벽을 만나지 않는지 && 함정 위치에 존재하는지 확인
        for(int i = nr[x]; i <= nr[x] + h[x] - 1; i++) {
            for(int j = nc[x]; j <= nc[x] + w[x] - 1; j++) {
                if(info[i][j] == 1) dmg[x]++; // 함정을 만나면 데미지를 입음
                if(info[i][j] == 2) return false; // 벽을 만나면 이동 불가능
            }
        }
        
        // 다른 조각들과 충돌하면 그것도 이동한다
        for(int i = 1; i <= n; i++) {
            if(is_moved[i] || k[i] <= 0) continue;
            if(r[i] > nr[x] + h[x] - 1 || nr[x] > r[i] + h[i] - 1) continue;
            if(c[i] > nc[x] + w[x] - 1 || nc[x] > c[i] + w[i] - 1) continue;

            q.push(i);
            is_moved[i] = true;
        }
    }

    dmg[idx] = 0; // 명령을 받은 기사는 데미지를 입지 않는다
    return true;
}

// 특정 기사를 지정된 방향으로 이동
void movePiece(int idx, int dir) {
    if(k[idx] <= 0) return;

    // 체력이 있는 경우, 실제 위치와 체력 구하기
    if(tryMove(idx, dir)) {
        for(int i = 1; i <= n; i++) {
            r[i] = nr[i];
            c[i] = nc[i];
            k[i] -= dmg[i];
        }
    }
}

int main() {
    // input
    cin >> l >> n >> q;

    for(int i = 1; i <= l; i++) {
        for(int j = 1; j <= l; j++){
            cin >> info[i][j]; 
        }
    }

    for(int i = 1; i <= n; i++) {
        cin >> r[i] >> c[i] >> h[i] >> w[i] >> k[i];
        bef_k[i] = k[i];
    }

    for(int i = 1; i <= q; i++) {
        int idx, dir;
        cin >> idx >> dir;
        movePiece(idx, dir);
    }

    long long answer = 0;
    for(int i = 1; i <= n; i++) {
        if(k[i] > 0) answer += bef_k[i] - k[i];
    }

    cout << answer;

    return 0;
}