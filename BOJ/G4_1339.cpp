//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<string> word;
//int alpha[26]; // � ���ĺ��� ���Ǿ����� Ȯ��
//int result = 0;
//
//void cal() {
//	for (int i = 0; i < word.size(); i++) {
//		int pow = 1;
//		for (int j = word[i].size() - 1; j >= 0; j--) {
//			int val = word[i][j] - 'A';
//			alpha[val] += pow;
//			pow *= 10; // �ڸ���  (���� �ڸ�, ���� �ڸ�,,,) ǥ�� ���
//		}
//	}
//	sort(alpha, alpha + 26); // ���� �������� ���� -> greedy
//
//	/*for (int i = 0; i < 26; i++) {
//		cout << alpha[i] << " ";
//
//	}*/
//
//	// ���� ������� ���� ����
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