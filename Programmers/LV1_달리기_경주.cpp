#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
// 3:12 - 3:29

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> player; map<int, string> order;
    
    // 선수-등수, 등수-선수
    for(int i = 0; i < players.size(); i++) {
        order[i] = players[i]; player[players[i]] = i;
    }
    
    for(int i = 0; i < callings.size(); i++) { // 역전
        string er = callings[i]; int er_order = player[er];
        int ee_order = er_order - 1; string ee = order[ee_order];
        
        // 추월
        player[er] = ee_order; order[ee_order] = er;
        player[ee] = er_order; order[er_order] = ee;    
    }
    
    for(auto it = order.begin(); it != order.end(); it++) 
        answer.push_back(it->second);
        
    return answer;
}