#include <iostream>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

int d[105][105]; // 플로이드에서는 인접 행렬
int N, M;

int main() {
    // input
	cin >> N >> M;

    // INF로 테이블 초기화
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            d[i][j] = INF;
        }
    }

    // 여러 가중치가 들어올 수 있으므로 최솟값
    while(M--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    // 자기자신 0으로 초기화
    for(int i = 1; i <= N; i++) d[i][i] = 0;

    // 플로이드-워샬
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(d[i][j] == INF) cout << "0 ";
            else cout << d[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}