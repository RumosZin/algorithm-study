#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N;
long long C;
vector<long long> v;
map<long long, int> m; // 숫자, 빈도 수
map<long long, int> order; // 숫자, 인덱스

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

	// 3. map의 value 기준 정렬 
	vector<pair<long long, int>> vec(m.begin(), m.end());
	sort(vec.begin(), vec.end(), cmp);

	// 4. value 개수만큼 출력
	for (int i = 0; i < vec.size(); i++) {
		for(int j = 0; j < vec[i].second; j++) cout << vec[i].first << " ";
	}
}