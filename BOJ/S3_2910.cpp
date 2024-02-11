#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N;
long long C;
vector<long long> v;
map<long long, int> m; // ����, �� ��
map<long long, int> order; // ����, �ε���

bool cmp(pair<long long, int> a, pair<long long, int> b) {
	if (a.second == b.second) return order[a.first] < order[b.first];
	return a.second > b.second;
}

int main() {

	// 1. input
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		long long input;
		cin >> input;
		m[input]++;

		if (order[input] == 0) order[input] = i + 1;
	}

	// 3. map�� value ���� ���� 
	vector<pair<long long, int>> vec(m.begin(), m.end());
	sort(vec.begin(), vec.end(), cmp);

	// 4. value ������ŭ ���
	for (int i = 0; i < vec.size(); i++) {
		for(int j = 0; j < vec[i].second; j++) cout << vec[i].first << " ";
	}
}