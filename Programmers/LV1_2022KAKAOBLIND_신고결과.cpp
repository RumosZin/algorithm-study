#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>

using namespace std;

// 2:15
// 각 유저는 한번에 한명 신고
// 신고 횟수에 제한 없음, 계속 신고 가능
// 한 유저 여러번 신고 되는데, 1회로 처리
// k번 이상은 이용 정지, 얘를 신고한 모든 유저들에게 정지 사실 보냄
// 모든 내용을 취합하여 한번에 이용정지 시키면서 정지 메일

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    map<string, int> reported; // 유저의 신고당한 횟수
    map<string, int> limited; // 제한 유저
    map<string, vector<string>> reporting; // 유저가 신고한 유저들
    set<string> s = set(report.begin(), report.end());
    
    // 신고 건수를 돌면서 신고 횟수 세기, 신고 유저들 매핑
    for(string rep : s) {
        string reporting_user = rep.substr(0, rep.find(' '));
        string reported_user = rep.substr(rep.find(' ') + 1);
    
        reported[reported_user]++;
        reporting[reporting_user].push_back(reported_user);  
    }
    
    // 신고 당한 횟수가 k 이상이면 제한 조치
    for(auto it = reported.begin(); it != reported.end(); it++) {
        if(it->second >= k) limited[it->first]++;
    }
    
    // 유저가 신고한 유저들을 순회
    for(string reporting_user : id_list) {
        // 신고자가 제한을 받았다면 메일을 받는다
        int limited_user_count = 0;
        vector<string> reported_users = reporting[reporting_user];
        
        for(string user : reported_users) {
            if(limited[user]) limited_user_count++;
        }
        
        answer.push_back(limited_user_count);
        
    }
    return answer;
}