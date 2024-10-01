#include <iostream>

using namespace std;

// 8:27
int bingo[5][5];
int answer = 0;

int check(int x) { // x를 지웠을 때 빙고가 몇 개가 되는지 확인

    // 빙고 칠하기
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(bingo[i][j] == x) {
                bingo[i][j] = 0; // x칠한 것과 같은 효과
                break;
            }
        }
    }

    // 빙고 갯수 세기 : 가로
    int count = 0;
    for(int i = 0; i < 5; i++) {
        bool find = true;
        for(int j = 0; j < 5; j++) {
            if(bingo[i][j] != 0) {
                find = false;
                break;
            }
        }
        if(find) count++;
    }  

    // 세로
    for(int i = 0; i < 5; i++) {
        bool find = true;
        for(int j = 0; j < 5; j++) {
            if(bingo[j][i] != 0) {
                find = false;
                break;
            }
        }
        if(find) count++;
    }  

    // 대각선
    bool find = true;
    bool find2 = true;
    for(int i = 0; i < 5; i++) {
        if(bingo[i][i] != 0) { find = false; }
        if(bingo[i][4 - i] != 0) { find2 = false; }
    }   
    if(find) count++;
    if(find2) count++; 
    
    return count;
}

int main() {
    // input
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> bingo[i][j];
        }
    }

    // bingo game
    int call;
    bool answer = false;
    int ans;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> call;
            int val = check(call);
            if(val >= 3 && !answer) {
                ans = i * 5 + j;
                answer = true;
            }
        }
    }

    cout << ans + 1;

    return 0;
}