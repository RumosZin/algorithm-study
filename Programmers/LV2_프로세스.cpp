#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
// 4:17 - 4:57 

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q; // 인덱스, 우선순위
    priority_queue<int> pq; 
    
    for(int i = 0; i < priorities.size(); i++) {
        q.push({i, priorities[i]}); pq.push(priorities[i]);
    }
    
    while(!q.empty()) {
        int idx = q.front().first; int pr = q.front().second; q.pop();
        
        if(pr == pq.top() && idx == location) { break; }
        else if(pr == pq.top()) { answer++; pq.pop(); }
        else { q.push({idx, pr}); }
    }
    
    return answer + 1;
}