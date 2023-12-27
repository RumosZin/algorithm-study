//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<string> word;
//int alpha[26]; // 어떤 알파벳이 사용되었는지 확인
//int result = 0;
//
//void cal() {
//	for (int i = 0; i < word.size(); i++) {
//		int pow = 1;
//		for (int j = word[i].size() - 1; j >= 0; j--) {
//			int val = word[i][j] - 'A';
//			alpha[val] += pow;
//			pow *= 10; // 자릿수  (일의 자리, 십의 자리,,,) 표현 방법
//		}
//	}
//	sort(alpha, alpha + 26); // 내림 차순으로 정렬 -> greedy
//
//	/*for (int i = 0; i < 26; i++) {
//		cout << alpha[i] << " ";
//
//	}*/
//
//	// 높은 순서대로 숫자 배정
//	int num = 9;
//	for (int i = 25; i >= 0; i--) {
//		if (alpha[i] == 0) break;
//		result += (alpha[i] * num);
//		num--;
//	}
//}
//
//int main() {
//	int num;
//	cin >> num;
//	string input;
//	for (int i = 0; i < num; i++) {
//		cin >> input;
//		word.push_back(input);
//	}
//	cal();
//	cout << result;
//
//}