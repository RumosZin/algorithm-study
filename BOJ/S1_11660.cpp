//#include <iostream>
//
//using namespace std;
//
//int M, N;
//
//int graph[1025][1025];
//int sum[1025][1025];
//
//int main() {
//	cin >> N >> M;
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			int num;
//			cin >> num;
//			graph[i][j] = num;
//			graph[i][j] += graph[i - 1][j] + graph[i][j - 1] - graph[i - 1][j - 1];
//			//cout << graph[i][j];
//		}
//	}
//
//	int x1, y1, x2, y2;
//
//	for (int t = 1; t <= M; t++) {
//		cin >> x1 >> y1 >> x2 >> y2;
//		x1 = x1 - 1;
//		y1 = y1 - 1;
//		cout << graph[x2][y2] - graph[x2][y1] - graph[x1][y2] + graph[x1][y1] << "\n";
//	}
//}