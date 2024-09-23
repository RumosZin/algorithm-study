#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// 6:02 - 6:26
// 7:34 - 7:57

vector<string> set_find(string str) {
    vector<string> s;
    for(int i = 0; i < str.size() - 1; i++) {
        string st = ""; 
        if(!isalpha(str[i]) || !isalpha(str[i + 1]) || 
           str[i] == ' ' || str[i + 1] == ' ') continue; 
        st += tolower(str[i]); st += tolower(str[i + 1]);
        s.push_back(st);
    }
    
    return s;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> s1; vector<string> s2;
    
    s1 = set_find(str1); s2 = set_find(str2);
    sort(s1.begin(), s1.end()); sort(s2.begin(), s2.end());
    
    vector<string> buff_union(s1.size() + s2.size()); 
    vector<string> buff_intersection(s1.size() + s2.size());
    
    auto it_union = set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), buff_union.begin());
    buff_union.erase(it_union, buff_union.end());
    auto it_iter = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), buff_intersection.begin());
    buff_intersection.erase(it_iter, buff_intersection.end());
    
    int a = buff_intersection.size();
    int b = buff_union.size();
    
    if(a == 0 && b == 0) { a = 1; b = 1; }
    
    answer = (65536 * a) / b;

    return answer;
}