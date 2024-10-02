#include <iostream>
#include <vector>

using namespace std;

// 3:47

int N;
vector<vector<int>> arr;

int minusone = 0;
int zero = 0;
int one = 0;

void check(int r, int c, int n) {
    // 넘겨받은 분면을 탐색
    bool equal = true;
    for(int i = r; i < r + n; i++) {
        for(int j = c; j < c + n; j++) {
            if(arr[i][j] != arr[r][c]) equal = false;
        }
        if(!equal) break;
    }

    // 같으면 더해줌
    if(equal) {
        if(arr[r][c] == 1) one++;
        else if(arr[r][c] == 0) zero++;
        else if(arr[r][c] == -1) minusone++;
    }
     
    // 같지 않으면 나눠서 재귀
    else {
        check(r, c, n/3);
        check(r, c+n/3, n/3);
        check(r, c+n/3+n/3, n/3);

        check(r+n/3, c, n/3);
        check(r+n/3, c+n/3, n/3);
        check(r+n/3, c+n/3+n/3, n/3);

        check(r+n/3+n/3, c, n/3);
        check(r+n/3+n/3, c+n/3, n/3);
        check(r+n/3+n/3, c+n/3+n/3, n/3);
    }
   
}

int main() {
    // input
    cin >> N;
    arr = vector<vector<int>>(2200, vector<int>(2200));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    check(0, 0, N); // 시작 row, 시작 col, 한 변의 길이 N

    cout << minusone << "\n" << zero << "\n"  << one << "\n";

    return 0;
}

