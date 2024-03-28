#include <iostream>

using namespace std;

long long A, B, C;

long long recursion(long long a, long long b, long long c) { // a = 10, b = 11, c = 12
	// cout << a << " " << b << " " << c << "\n";

	if (b == 0) {
		return 1;
	}

	long long ret = recursion(a, b / 2, c);
	if (b % 2 == 1) return ((ret * ret) % c) * a % c;
	else return (ret * ret) % c;
}

int main() {
	cin >> A >> B >> C;
	
	cout << recursion(A % C, B, C);
}