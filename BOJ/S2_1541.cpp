#include <iostream>
#include <string>

using namespace std;

int main() {

	// 1. input
	string input;
	cin >> input;

	// 2. parsing
	bool isMinus = false;
	int result = 0;
	string num;
	for (int i = 0; i <= input.size(); i++) {

			
		if (input[i] == '-' || input[i] == '+' || i == input.size()) {
			if (isMinus) { // minus
				result -= stoi(num);
				num = "";
			}
			else { // plus
				result += stoi(num);
				num = "";
			}
		}
		else {
			num += input[i];
		}

		if (input[i] == '-') isMinus = true;
	}

	cout << result;

}