#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

// 01:23
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

int time_to_second_int(string time) {
    return stoi(time.substr(0, time.find(':'))) * 60 + stoi(time.substr(time.find(':') + 1));
}

int next(int pos) {
    if(pos + 10 > total_ss) return total_ss;
    else return pos + 10;
}

int prev(int pos) {
    if(pos - 10 < 0) return 0;
    else return pos - 10;
}

int skip_opening(int pos) {
    if(pos >= opening_start_ss && pos <= opening_end_ss) return opening_end_ss;
    else return pos;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";

    total_ss = time_to_second_int(video_len);
    pos_ss = time_to_second_int(pos);
    opening_start_ss = time_to_second_int(op_start);
    opening_end_ss = time_to_second_int(op_end);    
    
    // command
    for(string cmd : commands) {
        pos_ss = skip_opening(pos_ss);
        
        if(cmd == "next") pos_ss = next(pos_ss);
        else pos_ss = prev(pos_ss);
        
        pos_ss = skip_opening(pos_ss);
    }
    
    // answer format
    int ans_mm = pos_ss / 60;
    if(ans_mm < 10) answer += "0" + to_string(ans_mm);
    else answer += to_string(ans_mm);
    
    answer += ":";
    
    int ans_ss = pos_ss % 60;
    if(ans_ss < 10) answer += "0" + to_string(ans_ss);
    else answer += to_string(ans_ss);
    
    return answer;
}