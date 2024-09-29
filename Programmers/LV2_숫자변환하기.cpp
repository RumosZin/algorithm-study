#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// 12:08

int solution(int x, int y, int n) {
    int answer = -1;
    queue<pair<long long, int>> q;
    set<long long> s; // 연산된 적 있는지 확인
    
    q.push(make_pair(x, 0)); s.insert(x);
    
    while(!q.empty()) {
        long long num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(num == y) {
            answer = cnt;
            break;
        }
        
        if(num + n <= y && s.find(num + n) == s.end()) {
            q.push(make_pair(num + n, cnt + 1));
            s.insert(num + n);
        }
        if(num * 2 <= y && s.find(num * 2) == s.end()) {
            q.push(make_pair(num * 2, cnt + 1));
            s.insert(num * 2);
        }
        if(num * 3 <= y && s.find(num * 3) == s.end()) {
            q.push(make_pair(num * 3, cnt + 1));
            s.insert(num * 3);
        }
    }
    
    return answer;
}