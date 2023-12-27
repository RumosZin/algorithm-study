#include <iostream>
#include <vector>

using namespace std;

int N;
vector<char> graph[27];
int visited[27] = { 0, };

void preorder(int input) { // A´Â 0¹øÂ°
	cout << char(input + 65);
	if (graph[input][0] != '.') { preorder(graph[input][0] - 'A'); }
	if (graph[input][1] != '.') { preorder(graph[input][1] - 'A'); }	
}

void inorder(int input) {
	if (graph[input][0] != '.') { inorder(graph[input][0] - 'A'); }
	cout << char(input + 65);
	if (graph[input][1] != '.') { inorder(graph[input][1] - 'A'); }
}

void postorder(int input) {
	if (graph[input][0] != '.') { postorder(graph[input][0] - 'A'); }
	if (graph[input][1] != '.') { postorder(graph[input][1] - 'A'); }
	cout << char(input + 65);
}

int main() {
	cin >> N;

	char me, leftchild, rightchild;

	for (int i = 1; i <= N; i++) {
		cin >> me >> leftchild >> rightchild;
		graph[me - 'A'].push_back(leftchild);
		graph[me - 'A'].push_back(rightchild);
	}

	preorder(0); cout << "\n";
	inorder(0); cout << "\n";
	postorder(0);
}