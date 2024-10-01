#include <iostream>

using namespace std;

// 5:22
int N;
int arr[64][64];
string answer = "";

void dfs(int r, int c, int n) {
    
    bool equal = true;
    for(int i = r; i < r + n; i++) {
        for(int j = c; j < c + n; j++) {
            if(arr[i][j] != arr[r][c]) equal = false;
        }
        if(!equal) break;
    }

    if(equal) {
        answer += to_string(arr[r][c]);
    }
    else {
        answer += "(";
        dfs(r, c, n/2);
        dfs(r, c + n/2, n/2);
        dfs(r + n/2, c, n/2);
        dfs(r + n/2, c + n/2, n/2);
        answer += ")";
    }
}

int main() {
    // input
    cin >> N;

    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < N; j++) {
            arr[i][j] = str[j] - '0';
        }
    }

    dfs(0, 0, N);

    cout << answer;

    return 0;
}