#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 4:17 - 4:57 다른 풀이 참고 ㅠ *max_element에 대해 알게 되었다

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q; // 인덱스, 우선순위
    vector<int> index;
    
    for(int i = 0; i < priorities.size(); i++) q.push({i, priorities[i]});
    
    while(!q.empty()) {
        int idx = q.front().first; int pr = q.front().second; q.pop();
        if(pr == *max_element(priorities.begin(), priorities.end())) {
            index.push_back(idx); priorities[idx] = 0;
        }
        else q.push({idx, pr});
    }
    
    for(int i = 0; i < index.size(); i++) {
        if(index[i] == location) { answer = i + 1; break; }
    }
    
    return answer;
}