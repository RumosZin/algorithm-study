#include <iostream>

using namespace std;

int T;
int N;

long long arr[101];

int main() {

	cin >> T; 

	for (int i = 1; i <= 3; i++) arr[i] = 1;
	arr[4] = 2;
	arr[5] = 2;

	for (int i = 0; i < T; i++) {
		// 1. input
		cin >> N;

		if (N <= 5) {
			cout << arr[N] << "\n";
			continue;
		}
		else {
			for (int i = 6; i <= N; i++) {
				arr[i] = arr[i - 1] + arr[i - 5];
			}
			cout << arr[N] << "\n";
			continue;
		}
	}
}