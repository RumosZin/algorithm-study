#include <iostream>
#include <vector>

// 5:!2
using namespace std;

int N;
int arr[128][128];
int white = 0;
int blue = 0;

void dfs(int r, int c, int n) {
    bool equal = true;
    for(int i = r; i < r + n; i++) {
        for(int j = c; j < c + n; j++) {
            if(arr[r][c] != arr[i][j]) equal = false;
        }
        if(!equal) break;
    }

    if(equal) {
        if(arr[r][c] == 0) white++;
        else blue++;
    }

    else {
        dfs(r, c, n/2);
        dfs(r, c + n/2, n/2);
        dfs(r + n/2, c, n/2);
        dfs(r + n/2 , c + n/2, n/2);
    }
}

int main() {
    // input
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0, 0, N);

    cout << white << "\n" << blue;

    return 0;
}