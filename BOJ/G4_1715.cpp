//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int N;
//int answer;
//
//int main() {
//	cin >> N;
//	
//	priority_queue<int> q; // �켱���� ť�� ����Ʈ�� �ִ��� root�� ����
//
//	for (int i = 1; i <= N; i++) {
//		int input;
//		cin >> input;
//		q.push(-1 * input);
//	}
//
//	if (q.size() == 1) {
//		cout << 0;
//		return 0;
//	}
//
//	while (!q.empty()) {
//		int first = q.top();
//		q.pop();
//		int second = q.top();
//		q.pop();
//
//		int next = first + second;
//		q.push(next);
//		answer += next;
//		if (q.size() == 1) {
//			//answer = q.top();
//			q.pop();
//			break;
//		}
//	}
//
//	cout << -1 * answer;
//}