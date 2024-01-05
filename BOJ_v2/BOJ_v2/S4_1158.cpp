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
//			q.pop(); // 3을 빼고
//			q.push(temp); // 맨 뒤에 넣는다 -> q하나로 바로 처리해서 memory 이득 가능
//
//		}
//		cout << q.front() << ", ";
//		q.pop(); // 출력한 숫자는 없어지므로 삭제함
//	}
//
//	cout << q.front() << ">\n";
//}
//
///*
//queue를 어떻게 했는지 까먹을 정도로 너무 오래 하지 않았다...
//queue의 가장 기본적인 예시 문제라고 생각함!
//*/