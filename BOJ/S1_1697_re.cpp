#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std; // 2:00 - 2:17

int N, K; // 수빈, 동생
int answer =  0;
int max_value;
set<int> s;

int main() {
    // input
    cin >> N >> K;
    queue<pair<int, int>> q;
    max_value = max(N, K) + 2;

    q.push({N, 0});
    s.insert(N);

    while(!q.empty()) {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();

        // stop condition
        if(num == K) {
            answer  = cnt;
            break;
        }

        if(num + 1 >= 0 && num + 1 <= max_value && s.find(num + 1) == s.end()) { 
            q.push({num + 1, cnt + 1});
            s.insert(num + 1);
        }
        if(num - 1 >= 0 && num - 1 <= max_value && s.find(num - 1) == s.end()) {
            q.push({num - 1, cnt + 1});
            s.insert(num - 1);
        }
        if(2 * num >= 0 && num * 2 <= max_value && s.find(num * 2) == s.end()) {
            q.push({2 * num, cnt + 1});
            s.insert(2 * num);
        }
    }

    cout << answer;
    return 0;
}