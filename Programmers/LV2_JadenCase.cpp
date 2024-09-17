#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// 12:50 - 1:20
// 모든 단어의 첫 대문자, 나머지 소문자
// 처음이 알파벳이 아니면 나머지는 소문자
// sstream으로 나눈 다음에 합치기 - 말고 다른 풀이가 더 대박..

string solution(string s) {
    string answer = "";
    
    answer += toupper(s[0]);
    for(int i = 1; i < s.size(); i++) {
        s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);
    }
    
    return answer;
}