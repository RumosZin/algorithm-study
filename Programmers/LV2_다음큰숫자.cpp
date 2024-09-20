#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 10:49 - 10:59
// n의 다음 큰 숫자
// n 보다 큰 자연수 / 이진수 변환 시 1의 개수 동일 / 12 만족 중 가장 작아야 함

int int_to_binary(int input) {
    int cnt = 0;
    while(input > 0) {
        if(input % 2 == 1) cnt++;
        input /= 2;
    }
    
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int origin_cnt = int_to_binary(n);
    while(1) {
        int cnt = int_to_binary(n + 1);
        if(cnt == origin_cnt) {
            answer = n + 1;
            break;
        }
        n++;
    }
    return answer;
}