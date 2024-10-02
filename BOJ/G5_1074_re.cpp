#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>

using namespace std;

// 5:57
int N, R, C;
int answer;

void dfs(long long r, long long c, int n, long long value) {
    // cout << r << " " << c << "  :  " << n << " " << value << "\n";
    // 정답 추출
    if(n == 2) {
        if(r == 0 && c == 0) answer = value;
        else if(r == 0 && c == 1) answer = value + 1;
        else if(r == 1 && c == 0) answer = value + 2;
        else answer = value + 3;
        return;
    }

    int field = n/2 * n/2;

    // 특정 사분면으로 이동한다
    if(r < n/2 && c < n/2) dfs(r, c, n/2, value);
    else if(r >= n/2 && c < n/2) dfs(r - n/2, c, n/2, value + field * 2);
    else if(r < n/2 && c >= n/2) dfs(r, c - n/2, n/2, value + field * 1);
    else dfs(r - n/2, c - n/2, n/2, value + field * 3);

    return;
}

int main(void) {
    // input
    cin >> N >> R >> C;

    dfs(R, C, pow(2, N), 0); // 시작r, 시작c, 한 변의 길이, 분면의 시작값

    cout << answer;

    return 0;
}