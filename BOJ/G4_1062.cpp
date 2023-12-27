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
//	if (count == K) { // 만약 K개를 다 뽑았다면 alphabet에 true가 되어있을 것임
//		bool read;
//		int cnt = 0;
//		for (int i = 0; i < N; i++) { // input 받은 모든 단어에 대해서 수행
//			read = true;
//			string str = word[i];
//			for (int j = 0; j < str.length(); j++) { // 단어의 알파벳이 뽑히지 않은거면 읽지 못하는 것임
//				if (alphabet[str[j] - 'a'] == false) {
//					read = false; break;
//				}
//			}
//			if (read) cnt++; // 읽을 수 있는 단어이므로 추가함
//		}
//		answer = max(answer, cnt); // 지금까지 읽을 수 있는 단어와 새로 계산한 읽을 수 있는 단어 중 max 기록함
//	}
//
//	for (int i = index; i < 26; i++) { // K개만큼 뽑지 않았으면, 더 뽑아야 함
//		if (alphabet[i] == true) continue; // 이미 뽑은 상태면 패스
//		alphabet[i] = true; // 그게 아니면 뽑았다 치고 그 인덱스부터 뒤로 쭉 뽑아야 함
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
//	// 26개 중에서 K개를 pick 해야함
//	dfs(0, 0); // 0번째부터 뽑기 시작해야함, 0개 뽑은 상태임
//
//	cout << answer;
//}