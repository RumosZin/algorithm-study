//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//vector<pair<int, int>> v;
//priority_queue<pair<int, int>> pq;
//priority_queue<int> left_seats; // 빈 자리 저장할 것
//int answer[100001];
//
//int main() {
//	cin >> N;
//
//	for (int i = 1; i <= N; i++) {
//		int P, Q;
//		cin >> P >> Q;
//		v.push_back({ P, Q });
//	}
//
//	sort(v.begin(), v.end());
//	int seat = 0;
//
//	for (int i = 0; i < v.size(); i++) {
//		//cout << v[i].first << " " << v[i].second << "\n";
//
//		while (!pq.empty()) {
//			// 다음으로 들어오는 사용자의 시작 시간과 이용중인 사용자의 끝나는 시간을 비교
//			// 다음 사용자가 들어오기 전에 끝난 사용자가 있으면, 자리 번호를 저장하고 pq에서 제거
//			if (-pq.top().first <= v[i].first) {
//				left_seats.push(-pq.top().second);
//				pq.pop();
//			}
//			else break;
//		}
//
//		if (left_seats.empty()) { // 빈 자리가 없을 때
//			pq.push({ -v[i].second, seat }); // (끝나는 시간, 자리)
//			answer[seat++]++;
//		}
//		else { // 빈자리가 있을 때
//			int tmp_seat = -left_seats.top();
//			left_seats.pop();
//			pq.push({ -v[i].second, tmp_seat });
//			answer[tmp_seat]++;
//		}		
//	}
//	cout << seat << "\n";
//	for (int i = 0; i < seat; i++) {
//		cout << answer[i] << " ";
//	}
//}