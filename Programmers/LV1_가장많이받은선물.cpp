#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 이번달기록 -> 다음달 예측
// A가 B 5, 3 : A가 더 많이 줌, A가 다음달에 하나 더 받음
// 없거나 같으면 : 선물 지수가 더 큰 사람이 작은 사람에게 하나 더 받음
// 선물 지수 : 준 선물 - 받은 선물
// 선물 지수도 같으면 선물을 주고받지 않음
// 다음 달에 선물을 가장 많이 받을 친구가 받을 선물의 수

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    map<string, int> gift_count; // 이름과 선물 지수
    map<string, int> friend_index; // 이름과 인덱스 매핑
    vector<vector<int>> gift_and_take(friends.size(), vector<int>(gifts.size(), 0)); // 이차원 배열
    map<string, int> next_gifts; // 다음 달에 받을 선물의 개수
    
    // 이름과 인덱스 매핑
    for(int i = 0; i < friends.size(); i++) {
        friend_index[friends[i]] = i;      
    }
    
    // 주고 받은 기록으로 선물 지수 계산
    for(int i = 0; i < gifts.size(); i++) {
        string s = gifts[i];
        int giver = friend_index[s.substr(0, gifts[i].find(' '))];
        int taker = friend_index[s.substr(gifts[i].find(' ') + 1)];
        
        gift_and_take[giver][taker] += 1;
        gift_count[friends[giver]]++;
        gift_count[friends[taker]]--;
     }
    
    // 선물 받는 개수 카운트
    for(int i = 0; i < friends.size(); i++) {
        for(int j = 0; j < friends.size(); j++) {
            if(i == j) continue;
            
            int give_count = gift_and_take[i][j];
            int take_count = gift_and_take[j][i];
            if(give_count > take_count) next_gifts[friends[i]]++;  
            
            else if((give_count == take_count) 
                    && (gift_count[friends[i]] > gift_count[friends[j]])) {
                next_gifts[friends[i]]++;
            }
        }
    }
    
                                                      
    for(auto it = next_gifts.begin(); it != next_gifts.end(); it++) {
        if(it->second > answer) answer = it->second;
    }
    
    return answer;
}