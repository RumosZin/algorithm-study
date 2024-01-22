#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000001

using namespace std;

int N; // 2 �̻� 11 ����
int input[11] = { 0, }; // ������ ���� ����, ���������� �ƴ� �� ����

vector<int> v; // ������ ��� ����

int ans_max = -1 * MAX;
int ans_min = MAX;


int main() {

	// 1. ���� �Է¹ޱ�
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}


	// 2. + - x % ���� �Է¹ޱ�
	int plus, minus, mult, div; // ���� 1, 2, 3, 4
	cin >> plus >> minus >> mult >> div; 

	// 3. ������ v�� �ֱ�
	for (int i = 0; i < plus; i++) v.push_back(1);
	for (int i = 0; i < minus; i++) v.push_back(2);
	for (int i = 0; i < mult; i++) v.push_back(3);
	for (int i = 0; i < div; i++) v.push_back(4);

	// 4. ���� ���� �ִ� ������ ���̽� ���ϰ� �� ����ϱ�
	do {

		// 4-1. ����ϱ�
		int answer = input[0];
		for (int i = 0; i < N - 1; i++) {
			if (v[i] == 1) {
				answer = answer + input[i + 1];
			}
			else if (v[i] == 2) {
				answer = answer - input[i + 1];
			}
			else if (v[i] == 3) {
				answer = answer * input[i + 1];
			}
			else {
				answer = answer / input[i + 1];
			}
			
		}

		// 4-3. min/max �Ǵ��ϱ�
		if (answer > ans_max) ans_max = answer;
		if (answer <= ans_min) ans_min = answer;
	} while (next_permutation(v.begin(), v.end()));
	
	cout << ans_max << "\n" << ans_min;
}

