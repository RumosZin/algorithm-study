#include <iostream>
#include <vector>

using namespace std;

// 12:14
// 시간 제한이 10초

int N;
int answer = 0;
vector<int> queen;

void backtracking(int cnt) { // 총 둔 퀸의 개수
    if(cnt == N) { // 퀸의 개수가 일치하면 카운트
        answer++;
        return;
    }

    for(int i = 0; i < N; i++) {
        queen[cnt] = i; // 행마다 한 명의 퀸이니까 cnt를 그대로 행으로 따져도 됨
        bool conflict = false;
        for(int j = 0; j < cnt; j++) {
            if(queen[cnt] == queen[j] || abs(queen[cnt] - queen[j]) == cnt - j) {
                conflict = true;
                break;
            }
        }
        if(!conflict) backtracking(cnt + 1);
    }

    return ;
}

int main() {

    // input
    cin >> N;
    queen.resize(N);

    // backtracking
    backtracking(0); // 현재까지 둔 퀸의 개수

    cout << answer << "\n";

    return 0;
}