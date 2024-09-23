#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 5:32

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> phone(phone_book.begin(), phone_book.end());
    
    for(string num : phone_book) {
        string st = "";
        for(int i = 0; i < num.size(); i++) {
            st += num[i]; 
            if(phone.find(st) != phone.end() && st != num) answer = false;
        }
    }
    
    return answer;
}