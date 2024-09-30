#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 8:30 - 8:45

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    set<string> s; // 탐색한 단어인지 확인
    queue<pair<string, int>> q; // 단어, 카운트
    
    q.push(make_pair(begin, 0));
    s.insert(begin);
    while(!q.empty()) {
        string w = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        // stop condition
        if(w == target) {
            answer = cnt;
            break;
        }
        
        // 한글자만 다른지 확인
        for(string word : words) {
            
            int diff = 0; // 다른 글자 개수
            if(s.find(word) != s.end()) continue;
            for(int i = 0; i < word.size(); i++) {
                if(word[i] == w[i]) continue;
                else diff++;
            }
            
            if(diff <= 1) {
                q.push(make_pair(word, cnt + 1));    
                s.insert(word);
            }
        }
    }
    
    return answer;
}