#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

// 10:48 - 11:11

vector<string> answer;
vector<pair<string, string>> order; // 출력 순서
map<string, string> name; // 유저 아이디, 이름

void enter(string id, string user_name) {
    name[id] = user_name;
    order.push_back(make_pair(id, "IN"));
}

void leave(string id) {
    order.push_back(make_pair(id, "OUT"));
}

void change(string id, string user_name) {
    name[id] = user_name;
}

vector<string> solution(vector<string> record) {
    vector<string> token;
    
    for(string re : record) {
        token.clear();
        stringstream ss(re);
        string re_tmp = "";
        
        while(getline(ss, re_tmp, ' ')) {
            token.push_back(re_tmp);
        }
        
        if(token[0] == "Enter") enter(token[1], token[2]); // 아이디, 이름
        else if(token[0] == "Leave") leave(token[1]); // 아이디
        else if(token[0] == "Change") change(token[1], token[2]); // 아이디, 이름
    }
    
    for(int i = 0; i < order.size(); i++) {
        string user_nm = name[order[i].first];
        string cmd = order[i].second;
        
        if(cmd == "IN") answer.push_back(user_nm + "님이 들어왔습니다.");
        else answer.push_back(user_nm + "님이 나갔습니다.");
    }
    return answer;
}