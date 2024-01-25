#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int alphabet[26];

string answer = "";
string temp = "";

int main() {

	// 1. input
	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		alphabet[input[i] - 'A']++;
	}

	// 2. 홀수 개인 alphabet이 2개 이상 있는지 확인
	int oddAlphabet = 0;
	int oddAlphabetIndex = -1;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] % 2 != 0) {
			oddAlphabet++;
			oddAlphabetIndex = i;
			// cout << "\t " << i << "\n";
 		}
	}
	if (oddAlphabet >= 2) {
		cout << "I\'m Sorry Hansoo";
		exit(0);
	}

	// 3. 홀수 개인 alphabet이 1개 이하이면 팰린드롬 만들기

	// 오름차순
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > 0) {
			for (int j = 0; j < alphabet[i] / 2; j++) {
				answer += i + 'A';
			}
		}
	}
	temp = answer;
	// 홀수 개인 alphabet 출력
	if (oddAlphabetIndex != -1) {
		answer += oddAlphabetIndex + 'A';
	}

	reverse(temp.begin(), temp.end());
	answer += temp;

	cout << answer;

}