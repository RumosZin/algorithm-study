#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;

vector<int> v; // 원하는 수열이 들어가 있음
queue<int> q; // stack에 넣을 숫자가 하나씩 들어가 있음

vector<int> stack; // stack
vector<int> answer;

int main() {

	// 1. 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input); // 원하는 수열을 순서대로 v에 넣음
		q.push(i + 1); // 숫자를 하나씩 q에 넣음
	}

	// 2. push, pop 연산 - 원하는 수열의 한글자씩 확인한다.
	// 

	/*for (int i = 0; i < n; i++) {
		cout << q.front() << "\n";
		q.pop();
	}*/
	
	bool find = false;
	int p = 0; // 원하는 수열의 숫자의 index
	while (!find) {

		// 원하는 숫자와 stack의 top 비교
		// 원하는 숫자 > stack top || stack size == 0 이면
		// 원하는 숫자까지 stack에 push하기
		if (stack.size() == 0 || v[p] > stack[stack.size() - 1]) {
			while (q.size() > 0 && q.front() <= v[p]) {
				//cout << "\t" << q.front() << " " << v[p] << "\n";
				int num = q.front();
				q.pop();
				stack.push_back(num);
				answer.push_back(0); // + == 0
			}
		}

		// 원하는 숫자 == stack top 이면
		// stack top 을 pop하기
		else if (stack[stack.size() - 1] == v[p]) {
			stack.pop_back();
			p++;
			answer.push_back(1); // - == 1
			//cout << stack.size() << " ";
		}
		
		else {
			answer.clear();
			find = true;
		}

		// 끝까지 수열을 구해서 정상 종료하는 경우
		if (p == n) {
			find = true;
		}
	
	}

	// 답안 출력
	if (answer.size() > 0) {
		for (int i = 0; i < answer.size(); i++) {
			
			if (answer[i] == 0) cout << "+\n";
			else cout << "-\n";
		}
	}
	else {
		cout << "NO";
	}

}