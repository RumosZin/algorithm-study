#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bits/stdc++.h>

// 8:38

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> order; // 캐시 순서 확인용
    set<string> cache;  // 캐시 존재 확인용
    
    for(string city : cities) {
        string temp = "";
        for(int i = 0; i < city.size(); i++) temp += tolower(city[i]);
        city = temp;
        if(find(order.begin(), order.end(), city) != order.end()) {
            order.remove(city); order.push_back(city);
            answer += 1; continue;
        }
        else if(cache.size() == cacheSize) { 
            if(cacheSize == 0) { answer += 5; continue; }
            cache.erase(order.front()); cache.insert(city);
            order.remove(order.front()); order.push_back(city);
            answer += 5;
        }
        else {
            order.push_back(city); cache.insert(city);
            answer += 5;
        }  
    }
    return answer;
}