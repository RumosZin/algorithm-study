#include <string>
#include <vector>
#include <bits/stdc++.h>

// 11:02

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long answer = 0; 
    int std = queue1.size() + queue2.size() + 2;
    queue<long long> q1; queue<long long> q2;
    long long sumA = 0; 
    long long sumB = 0;
    long long avg = (sumA + sumB) / 2;
    
    for(long long a : queue1) {
        sumA += a;
        q1.push(a);
    }
    for(long long b : queue2) {
        sumB += b;
        q2.push(b);
    }
    
    while(answer <= std) {
        if(sumA == sumB) break;
        
        if(sumA > sumB) {
            long long A = q1.front(); 
            q1.pop(); q2.push(A);
            sumA -= A; sumB += A;
        }
        
        else if(sumA < sumB) {
            long long B = q2.front(); 
            q2.pop(); q1.push(B);
            sumB -= B; sumA += B;
        }
        answer++;
    }
    
    if(answer > std) answer = -1;
    
    return answer;
}