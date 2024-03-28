//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//
//	int T;
//	cin >> T;
//
//	for (int i = 0; i < T; i++) {
//
//		// 1. DP 초기화
//		vector<int> zero_count;
//		vector<int> one_count;
//
//		zero_count.push_back(1);
//		zero_count.push_back(0);
//		one_count.push_back(0);
//		one_count.push_back(1);
//
//		// 2. 입력 받기
//		int n;
//		cin >> n;
//
//		if (n == 0) cout << "1" << " " << "0" << "\n";
//		else if (n == 1) cout << "0" << " " << "1" << "\n";
//		else {
//			for (int i = 2; i <= n; i++) {
//				zero_count.push_back(zero_count[i - 1] + zero_count[i - 2]);
//				one_count.push_back(one_count[i - 1] + one_count[i - 2]);
//
//				if (i == n) {
//					int zero = zero_count[n];
//					int one = one_count[n];
//
//					cout << zero << " " << one << "\n";
//				}
//			}
//		}
//	}
//
//}