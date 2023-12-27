//#include <iostream>
//#include <queue>
//#define MAX 100000
//
//using namespace std;
//
//int N, K;
//int due;
//int tc;
//int visited[100001];
//
//int main() {
//	cin >> N >> K;
//
//	queue<pair<int, int>> q;
//	q.push(make_pair(N, 0)); // 수빈이 위치 넣기
//	due = 0;
//	tc = 0;
//	visited[N] == 1;
//
//	bool find = false;
//	while (!q.empty()) {
//		int current = q.front().first;
//		int current_answer = q.front().second;
//		q.pop();
//		visited[current] = 1;
//
//		if (current == K) {
//			if(!find)	cout << current_answer << "\n";
//			due = current_answer; // due까지 확인해야함
//			tc++;
//			find = true;
//			if (q.empty()) cout << tc;
//			continue; // 다른 값 추가하지 않고 같은 level 다음 노드 확인함
//		}
//
//		if (find == true && current_answer > due) {
//			cout << tc;
//			break;
//		}
//
//		int first = current - 1;
//		int second = current + 1;
//		int third = current * 2;
//
//		if (first >= 0 && first <= MAX && visited[first] == 0) { q.push(make_pair(first, current_answer + 1)); }
//		if (second >= 0 && second <= MAX && visited[second] == 0) { q.push(make_pair(second, current_answer + 1)); }
//		if (third >= 0 && third <= MAX && visited[third] == 0) { q.push(make_pair(third, current_answer + 1)); }
//	}
//}