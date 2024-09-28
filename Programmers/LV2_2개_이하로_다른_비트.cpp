#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 2:18
// 비트로 다음 큰 수 찾는 방법 정리 pr ok

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long num : numbers) {
        if(num % 2 == 0) answer.push_back(num + 1);
        else {
            long long last_zero = (num + 1) & (-num);
            long long number = (num | last_zero) & (~(last_zero >> 1));
            answer.push_back(number);
        }
    }
    return answer;
}