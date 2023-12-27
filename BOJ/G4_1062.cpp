//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N, K, answer;
//
//string word[51];
//bool alphabet[26];
//
//vector<char> pick;
//
//void dfs(int index, int count) {
//	if (count == K) { // ���� K���� �� �̾Ҵٸ� alphabet�� true�� �Ǿ����� ����
//		bool read;
//		int cnt = 0;
//		for (int i = 0; i < N; i++) { // input ���� ��� �ܾ ���ؼ� ����
//			read = true;
//			string str = word[i];
//			for (int j = 0; j < str.length(); j++) { // �ܾ��� ���ĺ��� ������ �����Ÿ� ���� ���ϴ� ����
//				if (alphabet[str[j] - 'a'] == false) {
//					read = false; break;
//				}
//			}
//			if (read) cnt++; // ���� �� �ִ� �ܾ��̹Ƿ� �߰���
//		}
//		answer = max(answer, cnt); // ���ݱ��� ���� �� �ִ� �ܾ�� ���� ����� ���� �� �ִ� �ܾ� �� max �����
//	}
//
//	for (int i = index; i < 26; i++) { // K����ŭ ���� �ʾ�����, �� �̾ƾ� ��
//		if (alphabet[i] == true) continue; // �̹� ���� ���¸� �н�
//		alphabet[i] = true; // �װ� �ƴϸ� �̾Ҵ� ġ�� �� �ε������� �ڷ� �� �̾ƾ� ��
//		dfs(i, count + 1);
//		alphabet[i] = false;
//	}
//}
//
//int main() {
//	cin >> N >> K;
//
//	
//	for (int i = 0; i < N; i++) {
//		string input;
//		string input_after;
//		cin >> input;
//		word[i] = input;
//
//	}
//
//	if (K < 5) {
//		cout << 0;
//		return 0;
//	}
//
//	alphabet['a' - 'a'] = true;
//	alphabet['c' - 'a'] = true;
//	alphabet['n' - 'a'] = true;
//	alphabet['t' - 'a'] = true;
//	alphabet['i' - 'a'] = true;
//
//	K = K - 5;
//	
//	// 26�� �߿��� K���� pick �ؾ���
//	dfs(0, 0); // 0��°���� �̱� �����ؾ���, 0�� ���� ������
//
//	cout << answer;
//}