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
//priority_queue<int> left_seats; // �� �ڸ� ������ ��
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
//			// �������� ������ ������� ���� �ð��� �̿����� ������� ������ �ð��� ��
//			// ���� ����ڰ� ������ ���� ���� ����ڰ� ������, �ڸ� ��ȣ�� �����ϰ� pq���� ����
//			if (-pq.top().first <= v[i].first) {
//				left_seats.push(-pq.top().second);
//				pq.pop();
//			}
//			else break;
//		}
//
//		if (left_seats.empty()) { // �� �ڸ��� ���� ��
//			pq.push({ -v[i].second, seat }); // (������ �ð�, �ڸ�)
//			answer[seat++]++;
//		}
//		else { // ���ڸ��� ���� ��
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