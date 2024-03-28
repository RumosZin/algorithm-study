//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	int T;
//	cin >> T;
//
//	int N, M;
//	for (int i = 0; i < T; i++) {
//		cin >> N >> M;
//
//		long long result = 1;
//		int r = 1;
//		for (int j = M; j > M - N; j--) {
//			result = result * j;
//			result = result / r;
//
//			r++;
//		}
//
//		cout << result << "\n";
//	}
//}
//
///*
//N개의 사이트 개수만큼 다리를 짓는다
//중요한 조건은 <다리끼리 서로 겹쳐질 수 없음!!
//즉, X = {1, 2, 3, 4} Y = {1, 2, 3, 4, 5, 6, 7} 일 때,
//1<= f(1) < f(2) < f(3) < f(4) <= 7의 조건이 있고
//따라서 7C4라는 식이 발생함!
//
//=> mCn을 구하는 것이 핵심임~!*/