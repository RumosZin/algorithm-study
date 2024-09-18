#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 2:47
// n의 다양한 표현, 투포인터

int solution(int n) {
    int answer = 0;
    int start = 1; int end = 1;
    int sum = 1;
    
    for(int i = 1; i <= n; i++) {
        if(sum < n) { end++; sum += end; }
        else if (sum > n) { sum -= start; start++; }
        else { sum -= start; start++; answer++; }
    }
    
    if(n == 1) return 1;
    return answer + 1;
}