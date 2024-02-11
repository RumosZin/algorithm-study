#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int N, M;


int main() {
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> M;

		vector<int> v;
		vector<int> m;

		// input A
		for (int i = 0; i < N; i++) {
			long long input;
			cin >> input;
			v.push_back(input);
		}

		// input B
		for (int i = 0; i < M; i++) {
			long long input;
			cin >> input;
			m.push_back(input);
		}

		sort(v.begin(), v.end());
		sort(m.begin(), m.end());

		int answer = 0;
		for (int i = 0; i < N; i++) {
			int left = 0;
			int right = M;
			while (left + 1 < right) {
				int mid = (left + right) / 2;
				if (v[i] > m[mid])left = mid;
				else right = mid;
			}
			answer += left;
			if (v[i] > m[left]) answer++;
		}

		cout << answer << "\n";

	}
}