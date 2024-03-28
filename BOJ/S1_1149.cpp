#include <iostream>
#include <algorithm>
#define RED 0
#define GREEN 1
#define BLUE 2

using namespace std;

int N;
int arr[1001][3];
long long dp[1001][3];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		arr[i][RED] = r;
		arr[i][GREEN] = g;
		arr[i][BLUE] = b;

		if (i == 1) {
			dp[i][RED] = r;
			dp[i][GREEN] = g;
			dp[i][BLUE] = b;
		} 
		else {
			dp[i][RED] = min(dp[i - 1][GREEN] + arr[i][RED], dp[i - 1][BLUE] + arr[i][RED]);
			dp[i][GREEN] = min(dp[i - 1][RED] + arr[i][GREEN], dp[i - 1][BLUE] + arr[i][GREEN]);
			dp[i][BLUE] = min(dp[i - 1][RED] + arr[i][BLUE], dp[i - 1][GREEN] + arr[i][BLUE]);
		}
	}

	long long minimum = 10000000;
	for (int i = 0; i < 3; i++) {
		if (minimum > dp[N][i]) minimum = dp[N][i];
	}

	cout << minimum;
}