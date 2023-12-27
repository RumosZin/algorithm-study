#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int result = 2000000000;
vector<int> num;

int main() {
	cin >> N;

	int number;
	for (int i = 0; i < N; i++) {
		cin >> number;
		num.push_back(number);
	}
	int start = 0;
	int end = N - 1;
	int one, two;

	while (start < end) {
		int temp = num[start] + num[end];
		int middle = abs(temp); // tempÀÇ Àı´ñ°ª
		if (result > middle) {
			result = middle;
			one = num[start];
			two = num[end];
		}
		if (temp > 0) end--;
		else start++;
	}

	cout << one << " " << two;
}