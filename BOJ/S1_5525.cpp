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

	// sol 1. substr�� ù��° index ��ȯ�ޱ�
	
	//// substr ����
	//for (int i = 0; i < 2 * N + 1; i++) {
	//	if (i % 2 == 1) sub_s.push_back('O');
	//	else sub_s.push_back('I');
	//}
	////cout << sub_s;

	//// find�� �̿��ؼ� sub_s�� s�� ��� �ִ���
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

	// sol 2. OI�� �� ��Ʈ�� �ΰ�, 2�� �����ϸ� ������ ����
	// N�� ������ answer ������Ŵ

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