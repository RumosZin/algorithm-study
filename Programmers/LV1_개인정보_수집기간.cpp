#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 9:45 - 10:09

int days(string date) {
    int yy = stoi(date.substr(0, 4));
    int mm = stoi(date.substr(5, 7));
    int dd = stoi(date.substr(8, 10));
    
    return (yy - 2000) * 336 + mm * 28 + dd;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> termsm;
    int today_days = days(today);
    
    // 약관 : 유효기간일수 map
    for(string term : terms) {
        string yack = term.substr(0, term.find(' '));
        int days = 28 * stoi(term.substr(term.find(' ') + 1));
        termsm[yack] = days;
    }
    
    // 가입일수 : 약관 확인
    for(int i = 0; i < privacies.size(); i++) {
        string privacy = privacies[i];
        int entered_days = days(privacy.substr(0, privacy.find(' ')));
        string yack_privacy = privacy.substr(privacy.find(' ') + 1);
        if(entered_days + termsm[yack_privacy] <= today_days)  answer.push_back(i + 1);        
    }
    
    return answer;
}
