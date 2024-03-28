#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int T;
int N;
vector<pair<int, int>> v;

bool custom_sort(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) return true;
	else { return false; }
}

int main() {
	cin >> T;
	
	for (int i = 0; i < T; i++) {

		// 1. input �Է¹ޱ�
		cin >> N;
		for (int j = 0; j < N; j++) {
			int paper, meet;
			cin >> paper >> meet;
			v.push_back({ paper, meet });
		}

		// 2. first ���� sort
		sort(v.begin(), v.end(), custom_sort);

		// 3. second_min���� ���� ���� ok check
		int second_min = 100001;
		int answer = 0;
		for (int k = 0; k < N; k++) {
			if (v[k].second < second_min) {
				second_min = v[k].second;
				answer++;
			}
			else {
				continue;
			}
		}

		// 4. answer ���
		cout << answer << "\n";

		// 5. v �ʱ�ȭ
		v.clear();
	}
}