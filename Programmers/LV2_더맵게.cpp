#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// 6:46 - 7:02

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int sc : scoville) pq.push(sc);
    
    while(pq.size() >= 2 && pq.top() < K) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        
        pq.push(first + second * 2);
        answer++;
    }
    
    if(pq.top() < K) return -1;
    
    return answer;
}