//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int N, x;
//
//int main() {
//	cin >> N;
//	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
//	priority_queue<int, vector<int>, greater<int>> q;
//	
//	for (int i = 0; i < N; i++) {
//		cin >> x;
//		if (x != 0) q.push(x);
//		else { // �Է��� 0�� ��� q���� ���� ���� ���� ����Ѵ�.
//			if (q.size() == 0) { cout << 0 << "\n"; }
//			else { // q�� ���� ��� �ϳ� �ִ� ��� front�� ����ϰ� �����Ѵ�.
//				cout << q.top() << "\n";
//				q.pop();
//			}
//		}
//	}
//}