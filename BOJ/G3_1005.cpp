//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int T;
//int N; //  �ǹ� ����
//int K; // �ǹ� ���� �Ǽ� ���� ��Ģ (10�� ����)
//
//int timebuild[51];
//int builded[51];
//vector<int> buildorder[51];
//int win;
//int answer;
//
//
//int main() {
//	cin >> T;
//
//	for (int t = 0; t < T; t++) {
//		answer = 0;
//		cin >> N >> K;
//		for (int i = 1; i <= N; i++) {
//			cin >> timebuild[i]; // �ǹ� �� �Ǽ��� �ɸ��� �ð�
//		}
//
//		int first, second;
//		for (int i = 1; i <= K; i++) {
//			cin >> first >> second;
//			buildorder[second].push_back(first);
//		}
//		cin >> win;
//
//		answer += timebuild[win];
//	}	
//}