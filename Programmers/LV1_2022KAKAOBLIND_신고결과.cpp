#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// 2:15 - 3:20

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    map<string, int> reported; // 유저의 신고당한 횟수
    map<string, int> limited; // 제한 유저
    map<string, string> dup; // 중복 방지
    map<string, set<string>> reporting; // 유저가 신고한 유저들
    set<string> s = set(report.begin(), report.end());
    
    // 1. 유저-신고당한 횟수 / 유저-신고자 목록
    for(string rep : s) {
        string reporting_user = rep.substr(0, rep.find(' '));
        string reported_user = rep.substr(rep.find(' ') + 1);
    
        reported[reported_user]++;
        reporting[reporting_user].insert(reported_user);  
    }
    
    // 2. 유저-신고당한 횟수에서 제한 조치
    for(auto it = reported.begin(); it != reported.end(); it++) {
        if(it->second >= k) limited[it->first]++;
    }
    
    // 3. 유저-신고자 목록 순회 : 제한 받은 유저 카운트
    for(string reporting_user : id_list) {
        int limited_user_count = 0;
        set<string> s = reporting[reporting_user];
        for(auto it = s.begin(); it != s.end(); it++) {
            if(limited[*it]) limited_user_count++;
        }    
        answer.push_back(limited_user_count);
        
    }
    return answer;
}