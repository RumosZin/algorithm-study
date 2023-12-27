//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int T;
//int N; //  건물 개수
//int K; // 건물 간의 건설 순서 규칙 (10만 이하)
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
//			cin >> timebuild[i]; // 건물 당 건설에 걸리는 시간
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