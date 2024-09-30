#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 1:35 - 2:08

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<int> done;
    
    queue<int> q;
    int idx = 0;
    int sum = 0;
    
    while(done.size() != truck_weights.size()) {
        if(q.size() == bridge_length) {
            int arrive = q.front();
            sum -= arrive;
            q.pop();
            if(arrive != 0) done.push_back(arrive);
        }
        
        if(q.size() < bridge_length && sum + truck_weights[idx] <= weight) {
            q.push(truck_weights[idx]);
            sum += truck_weights[idx];
            idx++;
        }
        else q.push(0);

        answer++;
    }
    
    return answer;
}