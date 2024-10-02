#include <iostream>
#include <vector>

using namespace std;

int N, M;
// N까지의 자연수 중에서 M개를 선택
// 같은 수를 여러 번 골라도 된다

vector<int> arr;

void backtracking(int x) { // 현재까지 x개 && x번째 arr에 값을 넣어야 한다
    if(x == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return ;
    }

    for(int i = 1; i <= N; i++) {
        arr[x] = i;
        backtracking(x + 1);
    }

}

int main() {
    // input
    cin >> N >> M;
    arr.resize(N + 1);

    backtracking(0); // 갯수를 지정하고, arr에 숫자를 넣는다

    return 0;
}