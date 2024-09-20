#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 11:28 - 11:33
// 말만 짝지어 제거하기지 사실은 괄호쌍 문제

int solution(string s)
{
    int answer = 1;
    vector<char> stack;
    stack.push_back(s[0]);

    for(int i = 1; i < s.size(); i++) {
        if(stack.back() == s[i]) { stack.pop_back(); }
        else stack.push_back(s[i]);
    }
    
    if(stack.size() != 0) answer = 0;

    return answer;
}