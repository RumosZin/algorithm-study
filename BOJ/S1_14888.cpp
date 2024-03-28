#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000001

using namespace std;

int N; // 2 이상 11 이하
int input[11] = { 0, }; // 들어오는 숫자 저장, 오름차순이 아닐 수 있음

vector<int> v; // 연산자 담고 있음

int ans_max = -1 * MAX;
int ans_min = MAX;


int main() {

	// 1. 숫자 입력받기
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}


	// 2. + - x % 개수 입력받기
	int plus, minus, mult, div; // 각각 1, 2, 3, 4
	cin >> plus >> minus >> mult >> div; 

	// 3. 연산자 v에 넣기
	for (int i = 0; i < plus; i++) v.push_back(1);
	for (int i = 0; i < minus; i++) v.push_back(2);
	for (int i = 0; i < mult; i++) v.push_back(3);
	for (int i = 0; i < div; i++) v.push_back(4);

	// 4. 같은 것이 있는 순열로 케이스 구하고 값 계산하기
	do {

		// 4-1. 계산하기
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

		// 4-3. min/max 판단하기
		if (answer > ans_max) ans_max = answer;
		if (answer <= ans_min) ans_min = answer;
	} while (next_permutation(v.begin(), v.end()));
	
	cout << ans_max << "\n" << ans_min;
}

