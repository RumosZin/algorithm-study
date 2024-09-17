#include <iostream>
#include <vector>
#include <algorithm>

// 12:46
// 길이가 같은 배열 A, B, 각 배열은 자연수
// 배열 A, B에서 각각 한개뽑아 두 수 곱하기, 누적 합!!!!
// 최종 합이 가장 작아야 한다 -> 하나는 내림차순, 하나는 오름차순! 수학
// 1 2 4
// 5 4 4
// 5 + 8 + 16 = 9

using namespace std;

bool cmp(int a, int b) {
    if(a > b) return true;
    else return false;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int length = A.size();

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), cmp);
    
    for(int i = 0; i < length; i++) {
        answer += A[i] * B[i];
    }

    return answer;
}