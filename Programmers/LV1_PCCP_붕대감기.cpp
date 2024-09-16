#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 1:10 - 1:55

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int max_health = health;
    
    int time = attacks[attacks.size() - 1][0]; // 몬스터의 마지막 공격
    int band_time = bandage[0];
    int x = bandage[1];
    int y = bandage[2];
    int seq = 0;
    
    map<int, int> attack;
    
    // 공격 시간과 공격량 map
    for(int i = 0; i < attacks.size(); i++) {
        attack[attacks[i][0]] = attacks[i][1];
    }
    
    // 시간에 따른 공격 체크
    for(int t = 1; t <= time; t++) {

        // 공격이 있으면 체력 감소, 연속 성공 초기화
        if(attack[t]) {
            seq = 0;
            health -= attack[t]; 
            if(health <= 0) return -1;
            continue;
        }
        
       // 공격이 없으면 체력 증가, 연속 성공
        else {
            seq++;
            if(health + x <= max_health) health += x;   
            else health = max_health;
        }
        
        // 연속 공격 성공 시 체력 증가
        if(seq == band_time) {
            seq = 0;
            if(health + y <= max_health) health += y;
            else health = max_health;
        }
    }
    
    if(health <= 0) answer = -1;
    else answer = health;
    
    return answer;
}