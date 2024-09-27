#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 11:47 -- 11:53

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> older;
    map<int, int> younger; // topping, count
    
    // initialize
    for(int i = 0; i < topping.size(); i++) 
        younger[topping[i]]++;
    
    for(int i = 0; i < topping.size(); i++) {
        if(younger.find(topping[i]) != younger.end()) {
            older[topping[i]]++;
            younger[topping[i]]--;
            if(younger[topping[i]] == 0) younger.erase(topping[i]);
        }
        
        if(older.size() == younger.size())
            answer++;
    }

    return answer;
}