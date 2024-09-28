#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 11:12 - 11:30 10점 stable_sort로 바로 해결

vector<string> parse(string str) {
    string head = "";
    int num_idx = 0; string number = "";
    for(int i = 0; i < str.size(); i++) {
        if(isalpha(str[i]) || str[i] == ' ' || str[i] == '-'
          || str[i] == '.') head += tolower(str[i]);
        else {
            num_idx = i; 
            break;
        }
    }
    
    for(int i = num_idx; i < str.size(); i++) {
        if(!isalpha(str[i]) || str[i] != ' ' || str[i] != '-' 
           || str[i] != '.') number += str[i];
        else break;
    }
    
    return {head, number};
}

bool cmp(string a, string b) {
    vector<string> prs_a = parse(a); 
    vector<string> prs_b = parse(b);
    string head_a = prs_a[0];
    int number_a = stoi(prs_a[1]);
    
    string head_b = prs_b[0];
    int number_b = stoi(prs_b[1]);
    
    // 비교
    if(head_a == head_b) {
        if(number_a == number_b) return false;
        else return number_a < number_b;
    }
    else return head_a < head_b;    
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    stable_sort(files.begin(), files.end(), cmp);
    answer = files;
    return answer;
}