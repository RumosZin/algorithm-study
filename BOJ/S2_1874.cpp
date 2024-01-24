#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;

vector<int> v; // ���ϴ� ������ �� ����
queue<int> q; // stack�� ���� ���ڰ� �ϳ��� �� ����

vector<int> stack; // stack
vector<int> answer;

int main() {

	// 1. �Է�
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back(input); // ���ϴ� ������ ������� v�� ����
		q.push(i + 1); // ���ڸ� �ϳ��� q�� ����
	}

	// 2. push, pop ���� - ���ϴ� ������ �ѱ��ھ� Ȯ���Ѵ�.
	// 

	/*for (int i = 0; i < n; i++) {
		cout << q.front() << "\n";
		q.pop();
	}*/
	
	bool find = false;
	int p = 0; // ���ϴ� ������ ������ index
	while (!find) {

		// ���ϴ� ���ڿ� stack�� top ��
		// ���ϴ� ���� > stack top || stack size == 0 �̸�
		// ���ϴ� ���ڱ��� stack�� push�ϱ�
		if (stack.size() == 0 || v[p] > stack[stack.size() - 1]) {
			while (q.size() > 0 && q.front() <= v[p]) {
				//cout << "\t" << q.front() << " " << v[p] << "\n";
				int num = q.front();
				q.pop();
				stack.push_back(num);
				answer.push_back(0); // + == 0
			}
		}

		// ���ϴ� ���� == stack top �̸�
		// stack top �� pop�ϱ�
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

		// ������ ������ ���ؼ� ���� �����ϴ� ���
		if (p == n) {
			find = true;
		}
	
	}

	// ��� ���
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