#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;

void backtracking(int x, int st) { // x개 && x번째에 숫자를 넣어야 한다
    if(x == M) {
        for(int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return ;
    }

    for(int i = st; i <= N; i++) {
        arr[x] = i;
        backtracking(x + 1, i);
    }
}

int main() {
    cin >> N >> M;
    arr.resize(N + 1);

    backtracking(0, 1); // 현재까지의 개수, 시작 숫자

    return 0;
}   