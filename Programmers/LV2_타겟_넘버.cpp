#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 8 :15 - 9: 06

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    vector<int> v; v.push_back(0);
    queue<int> q; q.push(0);
    
    for(int i = 1; i <= numbers.size(); i++) {
        for(int j = 0; j < pow(2, i - 1); j++) {
            int num = q.front(); q.pop();
            q.push(num + numbers[i - 1]);
            q.push(num - numbers[i - 1]);
        }
    }
    
    while(!q.empty()) {
        int num = q.front(); q.pop();
        if(num == target) answer++;
    }

    return answer;
}