#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<long long, long long>> v;
int answer = 0;

bool custom_compare(pair<long long, long long> a, pair<long long, long long> b) {
	if (a.second < b.second) return true;
	else if (a.second > b.second) return false;
	else {
		if (a.first < b.first) return true;
		else return false;
	}
}


int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		long long start, end;
		cin >> start >> end;
		v.push_back({ start, end });
	}

	// 정렬의 기준? -> 끝나는 시간이 빨라야, 뒤에 더 많은 것들을 채울 수 있음!!
	// => 즉, 그리디 알고리즘을 사용해야 함

	// 1. 끝나는 시간 기준 정렬
	sort(v.begin(), v.end(), custom_compare);

	// 2. v[0]부터 선택해서 개수 세기
	int current_start;
	int current_end;
	for (int i = 0; i < N; i++) {
		if (i == 0) {

			//cout << v[i].first << " " << v[i].second << "\n";
			answer++;
			current_start = v[i].first;
			current_end = v[i].second;
			continue;
		}
		
		else {
			if (v[i].first >= current_end) {
				//cout << v[i].first << " " << v[i].second << "\n";
				answer++;
				current_start = v[i].first;
				current_end = v[i].second;
				continue;
			}
			
		}
	}

	//for (int i = 0; i < N; i++) cout << "\t" << v[i].first << " " << v[i].second << " " << "\n";

	cout << answer;

	
}