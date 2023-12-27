//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int S;
//int visited[2001][2001] = { 0, };
//
//int main() {
//	cin >> S;
//
//	queue<pair<pair<int, int>, int>> q; // 나, 보드, 시간
//	q.push(make_pair(make_pair(1, 0), 0));
//
//	while (!q.empty()) {
//		int cur = q.front().first.first;
//		int board = q.front().first.second;
//		int time = q.front().second;
//		q.pop();
//
//		visited[cur][board] = 1;
//
//		if (cur == S) { cout << time; break; }
//
//		if (visited[cur][cur] != 1 && cur > 0 && cur < 2001) 
//			q.push(make_pair(make_pair(cur, cur), time + 1));
//
//		if (visited[cur + board][board] != 1 && board >0 && cur + board < 2001) 
//			q.push(make_pair(make_pair(cur + board, board), time + 1));
//
//		if (visited[cur - 1][board] != 1 && cur > 0 && cur < 2001) 
//			q.push(make_pair(make_pair(cur - 1, board), time + 1));
//
//	}
//
//}