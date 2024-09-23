#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> num; // 숫자, 개수
    s = s.substr(1, s.size() - 1);
    
    string subs = ""; bool checking = false;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '{') { checking = true; continue; }
        else if(s[i] == '}') { 
            stringstream ss(subs); string temp = "";
            while(getline(ss, temp, ',')) { num[stoi(temp)]++; }
            checking = false; subs = ""; 
        }
        
        if(checking) subs += s[i];
    }
    
    vector<pair<int, int>> v(num.begin(), num.end());
    sort(v.begin(), v.end(), cmp);
    for(pair<int, int> number : v) { answer.push_back(number.first); }
    
    return answer;
}