#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
string s;
string sub_s;
int answer = 0;

int main() {
	
	// 1. input
	cin >> N >> M;
	cin >> s;

	// sol 1. substr의 첫번째 index 반환받기
	
	//// substr 생성
	//for (int i = 0; i < 2 * N + 1; i++) {
	//	if (i % 2 == 1) sub_s.push_back('O');
	//	else sub_s.push_back('I');
	//}
	////cout << sub_s;

	//// find를 이용해서 sub_s가 s의 어디에 있는지
	//int cur_index = 0;
	//for (int i = cur_index; i < M; i++) {
	//	int i_index = s.find(sub_s, cur_index);
	//	if (i_index != string::npos) answer++;

	//	if (i_index < i) break;
	//	i = i_index;
	//	cur_index = i_index + 1;
	//	//cout << i_index << "d";
	//}

	//cout << answer;

	// sol 2. OI를 한 세트로 두고, 2씩 증가하며 개수를 세고
	// N과 같으면 answer 증가시킴

	for (int i = 1; i < s.size(); i++) {
		int count = 0;
		if (s[i - 1] == 'I') {
			while (s[i] == 'O' && s[i + 1] == 'I') {
				i += 2;
				count++;
				if (count == N) {
					count--;
					answer++;
					
				}
			}
		}
	}

	cout << answer;
}