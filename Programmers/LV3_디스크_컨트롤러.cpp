#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 4:49

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        if(a[1] > b[1]) return true;
        return false;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0; 
    int index = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    sort(jobs.begin(), jobs.end());
    
    while(index < jobs.size()|| !pq.empty()) {
        if(index < jobs.size() && time >= jobs[index][0]) {
            pq.push(jobs[index]);
            index++;
            continue;
        }
        
        if(!pq.empty()) {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else time = jobs[index][0];    
    }
    
    answer /= jobs.size();
    
    return answer;
}