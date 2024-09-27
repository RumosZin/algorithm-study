#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

// 10:25 - 10:51 
// 25 + 18 = 43분

int time_to_minute(string t) {
    string h = t.substr(0, 2);
    string m = t.substr(3);
    
    return stoi(h) * 60 + stoi(m);
}

int ollim(int a, int b, int c) {
    if((a - b) % c  == 0) return (a-b)/c;
    else return (a-b)/c + 1;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> sumTime;
    map<string, int> inTime;
    priority_queue<int> pq;
    int last = 23 * 60 + 59;
    
    // 입차, 출차에 따른 누적 시간 계산
    for(string re : records) {
        string time = re.substr(0, 5);
        string car = re.substr(6, 4);
        string inout = re.substr(11);
        
        if(inout == "IN") inTime[car] = time_to_minute(time);
        else { 
            int out = time_to_minute(time); int in = inTime[car];
            inTime.erase(car);
            sumTime[car] += out - in;
        }
    }
    
    for(auto it = inTime.begin(); it != inTime.end(); it++) {
        string left_car = it->first;
        int left_in = it->second;
        sumTime[left_car] += last - left_in;
        inTime.erase(left_car);
    }
    
    // 주차 요금 계산
    for(auto it = sumTime.begin(); it != sumTime.end(); it++) {
        int cost = fees[1] + ollim(it->second, fees[0], fees[2]) * fees[3];
        if(it->second < fees[0]) cost = fees[1];
        answer.push_back(cost);
    }
    
    return answer;
}