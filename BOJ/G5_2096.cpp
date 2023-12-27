//#include <iostream>
//#include <algorithm>
//#define INF 1000000
//
//using namespace std;
//
////int table[100001][3];
//int dpmax[3] = { 0, };
//int dpmin[3] = { 0, };
//int N;
//
//int main() {
//	cin >> N;
//
//	int zero, first, second;
//	cin >> zero >> first >> second;
//	dpmax[0] = zero; dpmin[0] = zero;
//	dpmax[1] = first; dpmin[1] = first;
//	dpmax[2] = second; dpmin[2] = second;
//
//	for (int i = 2; i <= N; i++) {
//		cin >> zero >> first >> second;
//		int max_value = 0;
//		int min_value = INF;
//
//		for (int i = 0; i < 3; i++) {
//			if (dpmin[i] <= min_value) min_value = dpmin[i];
//			if (dpmax[i] >= max_value) max_value = dpmax[i];
//
//			//cout << dpmax[i] << " dd " << dpmin[i] << " ff ";
//		}
//
//		int before_zero = dpmax[0];
//		int before_first = dpmax[1];
//		int before_second = dpmax[2];
//
//		dpmax[0] = max(before_zero, before_first) + zero;
//		dpmax[1] = max_value + first;
//		dpmax[2] = max(before_first, before_second) + second;
//
//
//		before_zero = dpmin[0];
//		before_first = dpmin[1];
//		before_second = dpmin[2];
//
//		dpmin[0] = min(before_zero, before_first) + zero;
//		dpmin[1] = min_value + first;
//		dpmin[2] = min(before_first, before_second) + second;
//	}
//
//	int max_value = 0;
//	int min_value = INF;
//
//	for (int i = 0; i < 3; i++) {
//		if (dpmin[i] <= min_value) min_value = dpmin[i];
//		if (dpmax[i] >= max_value) max_value = dpmax[i];
//
//		//cout << dpmax[i] << " dd " << dpmin[i] << " ff ";
//	}
//
//	cout << max_value << " ";
//	cout << min_value;
//}