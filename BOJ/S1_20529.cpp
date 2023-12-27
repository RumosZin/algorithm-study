//#include <iostream>
//#define INF 100001
//
//using namespace std;
//
//int T;
//int N;
//int answer;
//
//string node[100001];
//
//int main() {
//
//	cin >> T;
//	for (int t = 0; t < T; t++) {
//		answer = INF;
//		cin >> N;
//		
//		for (int i = 1; i <= N; i++) {	cin >> node[i];	}
//
//		if (N > 32) {
//			cout << 0 << "\n";
//			continue;
//		}
//
//		for (int i = 1; i <= N; i++) { // ��� �־��� �� �ֿ� ���ؼ� Ȯ���Ѵ�.
//			for (int j = i + 1; j <= N; j++) {
//
//				int distance = 0;
//				if (node[i][0] != node[j][0]) distance++; // E, I
//				if (node[i][1] != node[j][1]) distance++;
//				if (node[i][2] != node[j][2]) distance++;
//				if (node[i][3] != node[j][3]) distance++;
//
//				if (distance < answer) { // ó�� answer�� INF�� ������
//					for (int k = 1; k <= N; k++) {
//						int value = INF;
//						if (k == i || k == j) continue;
//
//						//i,k ������ �Ÿ� Ȯ��
//						int distance_i = 0;
//						int distance_j = 0;
//
//						if (node[i][0] != node[k][0]) distance_i++; // E, I
//						if (node[j][0] != node[k][0]) distance_j++;
//
//						if (node[i][1] != node[k][1]) distance_i++; // N, S
//						if (node[j][1] != node[k][1]) distance_j++;
//
//						if (node[i][2] != node[k][2]) distance_i++; // T, F
//						if (node[j][2] != node[k][2]) distance_j++;
//
//						if (node[i][3] != node[k][3]) distance_i++; // J, P
//						if (node[j][3] != node[k][3]) distance_j++;
//
//						//value = min(distance_i, distance_j); // i, j�� ���� ���� ���̸� ���� ���� value
//						answer = answer < distance + distance_i + distance_j ? answer : distance + distance_i + distance_j;
//					}
//				}
//			}
//		}
//		cout << answer << "\n";
//	}
//}