#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zero = 0; int count = 0;
    
    while(s != "1") {
        // erase 0
        int before_len = s.size();
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        int after_len = s.size();
        
        zero += before_len - after_len; 
        count++;

        // convert binary   
        string string_s = "";
        while(after_len > 0) {
            string_s += (after_len % 2 == 0 ? "0" : "1");
            after_len /= 2;
        }
        reverse(string_s.begin(), string_s.end());
        s = string_s; 
    }
    answer.push_back(count); answer.push_back(zero);
    return answer;
}