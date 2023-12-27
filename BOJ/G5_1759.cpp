//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int L, C;
//vector<pair<char, bool>> alphabet;
//
//int ja, mo;
//
//void dfs(int index, int count) {
//	if (count == L) { // 자음 2개 이상, 모음 1개 이상 조건 확인 해야 함
//		ja = 0;
//		mo = 0;
//		for (int i = 0; i < alphabet.size(); i++) {
//			if (alphabet[i].second == false) continue;
//			
//			if (alphabet[i].first == 'a'
//				|| alphabet[i].first == 'e'
//				|| alphabet[i].first == 'i'
//				|| alphabet[i].first == 'o'
//				|| alphabet[i].first == 'u') mo++;
//			else { ja++; }
//		}
//		if (ja >= 2 && mo >= 1) {
//			for (int i = 0; i < alphabet.size(); i++) {
//				if (alphabet[i].second == false) continue;
//				cout << alphabet[i].first;
//			}
//			//cout << " " << ja << " " << mo;
//			cout << "\n";
//		}
//	}
//
//	for (int i = index; i < alphabet.size(); i++) {
//		if (alphabet[i].second == true) continue;
//		alphabet[i].second = true;
//		dfs(i, count + 1);
//		alphabet[i].second = false;
//	}
//
//}
//
//int main() {
//	cin >> L >> C;
//	ja = 0;
//	mo = 0;
//
//	for (int i = 0; i < C; i++) {
//		char input;
//		cin >> input;
//		alphabet.push_back({ input, false });
//	}
//
//	sort(alphabet.begin(), alphabet.end());
//
//	dfs(0, 0);
//}