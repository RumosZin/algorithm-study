#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 3:20 - 3:52
// 재귀 구현!

map<int, int> cnt;
vector<vector<int>> ar;

int pow_check(int n) {
    int count = 0;
    while(n > 0) {
        n /= 2; 
        count++;
    }
    return count;
}

bool correct(int a, int b, int c, int d) { // 1, 0 리턴된 게 다 같으면
    return a == b && b == c && c == d;
}

int same(int row, int col, int pow) {
    if(pow == 1) {
        return ar[row][col]; // 어떤 숫자로 같아야 하는지 반환
    }
    
    int half = pow / 2;
    int a = same(row, col, half);
    int b = same(row, col + half, half);
    int c = same(row + half, col, half);
    int d = same(row + half, col + half, half);
    if(correct(a, b, c, d)) {
        return a;
    }
    
    else {
        cnt[a]++; cnt[b]++;
        cnt[c]++; cnt[d]++;
        return -1;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    ar = arr;
    
    int r = arr.size(); int c = arr[0].size();
    int pw = pow_check(r);
    
    int result = same(0, 0, r);
    if(result != -1)
        cnt[result]++;
    
    return { cnt[0], cnt[1] };
}