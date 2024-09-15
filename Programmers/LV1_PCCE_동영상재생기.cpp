#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

// 01:23 - 2:00
// 10초 전으로 이동 - prev, 0 or 10초 전
// 10초 후로 이동 - next, 마지막 or 10초 후
// 오프닝 건너뛰기 - <현재 재생 위치>가 op_start 이상 op_end인 경우 오프닝 끝 위치로 이동
// 사용자의 입력이 모두 끝난 후 동영상의 위치 구하기
// prev, next가 명령어로 주어지고 위치 계산 후 오프닝 건너뛰기를 해야하면 그거 수행하면 됨
// 조건 복잡한 구현 문제

int video_mm;
int video_ss;
int total_ss;
int pos_ss;
int opening_start_ss;
int opening_end_ss;

int next(int pos) {
    if(pos + 10 > total_ss) return total_ss;
    else return pos + 10;
}

int prev(int pos) {
    if(pos - 10 < 0) return 0;
    else return pos - 10;
}

int skip_opening(int pos) {
    if(pos >= opening_start_ss && pos <= opening_end_ss) {cout << "here";return opening_end_ss;}
    else return pos;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    video_mm = stoi(video_len.substr(0, video_len.find(':')));
    video_ss = stoi(video_len.substr(video_len.find(':') + 1));
    total_ss = video_mm * 60 + video_ss;
    pos_ss = stoi(pos.substr(0, pos.find(':'))) * 60 + stoi(pos.substr(pos.find(':') + 1));
    opening_start_ss = stoi(op_start.substr(0, op_start.find(':'))) * 60 + stoi(op_start.substr(op_start.find(':') + 1));
    opening_end_ss = stoi(op_end.substr(0, op_end.find(':'))) * 60 + stoi(op_end.substr(op_end.find(':') + 1));
    
    for(int i = 0; i < commands.size(); i++) {
        pos_ss = skip_opening(pos_ss);
        
        if(commands[i] == "next") pos_ss = next(pos_ss);
        else pos_ss = prev(pos_ss);
        
        pos_ss = skip_opening(pos_ss);
    }
    
    int ans_mm = pos_ss / 60;
    if(ans_mm < 10) answer += "0" + to_string(ans_mm);
    else answer += to_string(ans_mm);
    
    answer += ":";
    
    int ans_ss = pos_ss % 60;
    if(ans_ss < 10) answer += "0" + to_string(ans_ss);
    else answer += to_string(ans_ss);
    
    return answer;
}