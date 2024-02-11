//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//int N;
//vector<string> v;
//bool cmp(string a, string b) {
//	//cout << a <<  " " << b << "\n";
//	if (a.size() < b.size()) return true;
//	else if (a.size() == b.size()) {
//		int total_a = 0;
//		int total_b = 0;
//
//		for (int i = 0; i < a.size(); i++) {
//			if (a[i] - '0' <= 9) total_a += a[i] - '0';
//			if (b[i] - '0' <= 9) total_b += b[i] - '0';
//		}
//
//		if (total_a < total_b) return true;
//		else if (total_a == total_b) {
//			if (a < b) return true;
//			else return false;
//		}
//		else return false;
//	}
//	else return false;
//}
//
//int main() {
//	cin >> N;
//
//	// 1. input
//	for (int i = 0; i < N; i++) {
//		string input;
//		cin >> input;
//		v.push_back(input);
//	}
//
//	// 2. sort
//	sort(v.begin(), v.end(), cmp);
//
//	// 3. output
//	for (int i = 0; i < N; i++) cout << v[i] << "\n";
//}
