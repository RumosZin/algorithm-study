//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int N, K;
//queue<int> q;
//
//int main() {
//	cin >> N >> K;
//
//	for (int i = 1; i <= N; i++) q.push(i);
//
//	cout << "<";
//
//	while (q.size() > 1) {
//		for (int i = 1; i < K; i++) {
//			int temp = q.front();
//			q.pop(); // 3�� ����
//			q.push(temp); // �� �ڿ� �ִ´� -> q�ϳ��� �ٷ� ó���ؼ� memory �̵� ����
//
//		}
//		cout << q.front() << ", ";
//		q.pop(); // ����� ���ڴ� �������Ƿ� ������
//	}
//
//	cout << q.front() << ">\n";
//}
//
///*
//queue�� ��� �ߴ��� ����� ������ �ʹ� ���� ���� �ʾҴ�...
//queue�� ���� �⺻���� ���� ������� ������!
//*/