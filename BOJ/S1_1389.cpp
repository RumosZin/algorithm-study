#include <iostream>
#define INF 1000000000

using namespace std;

int N, M;
int dist[101][101];

int main() {


	
	// 1. input
	cin >> N >> M;

	// 2. setting
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = INF;
			if (i == j) dist[i][j] = 0;
		}
	}

	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	// 3. floyd-warshall
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int answer_value = INF;
	int answer;
	for (int i = 1; i <= N; i++) {
		int total = 0;
		for (int j = 1; j <= N; j++) {
			total += dist[i][j];
		}
		// cout << total << "Dd";
		if (answer_value > total) { 
			answer = i; 
			answer_value = total;
		}
	}
	cout << answer;
}