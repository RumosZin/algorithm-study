#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 9:05 - 9:39

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> temporary;
    map<char, int> count; // 스킬, 선행해야 하는 스킬 수
    vector<vector<char>> alpha(26); // C 이면 인덱스 2, 다음에 수행할 것들 저장
    
    for(int i = 0; i < skill.size(); i++) temporary[skill[i]] = i;
    for(int i = 0; i < skill.size(); i++) {
        for(int j = i + 1; j < skill.size(); j++) {
            alpha[skill[i] - 'A'].push_back(skill[j]);
        }
    }
    
    for(string st : skill_trees) {
        int p = 0;
        count = temporary;
        bool find = true;
        while(p < st.size()) {
            char c = st[p];
            if(count[c] != 0) { find = false; break; }
            if(count.find(c) == count.end()) { p++; continue; }
   
            count.erase(c); // 0이니까 맵에서 삭제
            for(int i = 0; i < alpha[c - 'A'].size(); i++) {
                count[alpha[c - 'A'][i]]--;
            }
            p++;
        }
        if(find) { answer++; }
        count.clear();
    }
    
    return answer;
}