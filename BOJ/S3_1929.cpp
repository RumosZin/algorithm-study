#include <iostream>

using namespace std;

int M, N;
int arr[1000001] = { 0, };

int main() {
	cin >> M >> N;

	for (int i = 2; i <= N; i++) {
		if (arr[i] == 0) { // i값의 배수 제거하기
			int thres = 2;
			while (i * thres <= N) {
				arr[i * thres]++;
				thres++;
			}			
		}
		else { continue; }
	}

	for (int i = M; i <= N; i++) {
		if (arr[i] == 0 && i != 1) cout << i << "\n";
		//else if (i == 1) continue;
	}

}