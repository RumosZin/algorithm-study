#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	// 1. input
	string input;
	getline(cin, input);

	// 2. parsing - tag / word
	bool tag = false;
	vector<char> word;
	for (int i = 0; i < input.size(); i++) {

		// tag '>'까지 찾아서 그대로 출력
		if (input[i] == '<') {
			
			if (word.size() != 0) {
				reverse(word.begin(), word.end());
				for (int i = 0; i < word.size(); i++) {
					cout << word[i];
				}
				word.clear();
			}
			tag = true;
			cout << input[i];
			continue;
		}
		else if (input[i] == '>') {
			tag = false;
			
			cout << input[i];
			continue;
		}
		else if(tag == true) {
			
			cout << input[i];
			continue;
		}
		

		// word는 담았다가 reverse 해서 출력
		else if (input[i] == ' ' || input[i] == '<') {
			if (word.size() != 0) {
				reverse(word.begin(), word.end());
				for (int i = 0; i < word.size(); i++) {
					cout << word[i];
				}
				word.clear();
				cout << " ";
				continue;
			}
			
		}		
		word.push_back(input[i]);
	}

	if (word.size() != 0) {
		reverse(word.begin(), word.end());
		for (int i = 0; i < word.size(); i++) {
			cout << word[i];
		}
	}
}