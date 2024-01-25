#include <iostream>
#include <algorithm>
#define MAX 100000001

using namespace std;

int n;
long long arr[100001][2]; // 0 - mine, 1 - maximum
long long answer = -1 * MAX;

int main() {

	// 1. input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0];
	}

	// 2. dp - mine and maximum
	arr[1][1] = -1001; // arr[1][0] = 10
	arr[0][1] = -1 * MAX;
	arr[0][0] = 0;
		
	for (int i = 1; i <= n; i++) {
		long long first = arr[i - 1][1] + arr[i][0]; // before max + mine
		long long second = arr[i - 1][0] + arr[i][0]; // before mine + mine

		int maximum_val = max(first, second);
		if (maximum_val > answer) answer = maximum_val;
		if (arr[i][0] > answer) answer = arr[i][0];
		arr[i][1] = maximum_val;
	}

	// 3. answer
	cout << answer;
}