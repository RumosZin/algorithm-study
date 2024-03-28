#include <iostream>
#include <queue>

using namespace std;

long long A, B;
int answer = 0;
queue<pair<long long, int>> q;

void BFS() {
	
	while (!q.empty()) {
		long long num = q.front().first;
		int count = q.front().second;
		q.pop();

		if (num == B) {
			answer = count + 1;
			return;
		}
		else { // 같지 않은 경우 전부 해야 함!

			// 1. 곱하기 2
			long long temp_num = num * 2;
			if(temp_num <= B) q.push({ temp_num, count + 1 });

			// 2. 뒤에 1 
			temp_num = num * 10 + 1;
			if(temp_num <= B) q.push({ temp_num, count + 1 });

		}
	}

	answer = -1;
}


int main() {

	cin >> A >> B;
	q.push(make_pair(A, 0));
	BFS();

	cout << answer;
}