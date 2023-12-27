//#include <iostream>
//#include <queue>
//#include <cstdlib>
//
//using namespace std;
//
//int N, x;
//
//struct cmp {
//	bool operator()(int a, int b) {
//		if (abs(a) == abs(b)) return a > b;
//		return abs(a) > abs(b);
//	}
//};
//
//int main() {
//	cin >> N;
//	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
//	priority_queue<int, vector<int>, cmp> q;
//
//	for (int i = 0; i < N; i++) {
//		cin >> x;
//		if (x != 0) q.push(x);
//		else { // 입력이 0인 경우 q에서 절댓값이 가장 작은 값을 출력한다.
//			if (q.size() == 0) { cout << 0 << "\n"; }
//			else { // q에 값이 적어도 하나 있는 경우 front를 출력하고 삭제한다.
//				cout << q.top() << "\n";
//				q.pop();
//			}
//		}
//	}
//}