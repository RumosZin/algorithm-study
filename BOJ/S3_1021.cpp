#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int main() {
    int answer = 0;
    // input
    int N, M;
    cin >> N >> M;

    deque<int> dq;
    for(int i = 1; i <= N; i++) dq.push_back(i);

    int idx;
    while(M--) {
        int num;
        cin >> num; // 찾고자 하는 수
         
        // 찾고자 하는 수의 dq에서의 위치 판단
        for(int i = 0; i < dq.size(); i++) {
            if(dq[i] == num) {
                idx = i;
                break;
            }
        }

        // front랑 가깝다면 2번
        if(idx <= dq.size() / 2) {
            while(dq.front() != num) {
                int f = dq.front();
                dq.pop_front();
                dq.push_back(f);
                answer++;
            }
            dq.pop_front(); // num도 삭제
        }

        // back이랑 가깝다면 3번
        else {
            while(dq.front() != num) {
                int b = dq.back();
                dq.pop_back();
                dq.push_front(b);
                answer++;
            }
            dq.pop_front();
        }
    }

    cout << answer;

    return 0;
}