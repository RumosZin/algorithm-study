//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int visited[26][26];
//int graph[26][26];
//int N;
//
//int dx[] = {1, -1, 0, 0};
//int dy[] = {0, 0, 1, -1};
//
//vector<int> dan;
//
//void DFS(int row, int col) {
//	visited[row][col] = 1;
//
//	for (int d = 0; d < 4; d++) {
//		int next_x = row + dx[d];
//		int next_y = col + dy[d];
//
//		if (next_x >= 1 && next_x <= N
//			&& next_y >= 1 && next_y <= N
//			&& graph[next_x][next_y] == 1
//			&& visited[next_x][next_y] != 1) {
//			//dan.end()++;
//			int count = dan.back();
//			dan.pop_back();
//			count++;
//			dan.push_back(count);
//			
//			DFS(next_x, next_y);
//		}
//	}
//}
//
//int main() {
//	cin >> N;
//	string input;
//	for (int i = 1; i <= N; i++) {
//		cin >> input;
//		for (int j = 1; j <= N; j++) {
//			graph[i][j] = input[j - 1] - '0';
//		}
//	}
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			if (graph[i][j] == 1 && visited[i][j] != 1){
//				dan.push_back(1);
//				DFS(i, j);
//			}
//		}
//	}
//	cout << dan.size() << "\n";
//	sort(dan.begin(), dan.end());
//	for (int i = 0; i < dan.size(); i++) {
//		cout << dan[i] << "\n";
//	}
//}