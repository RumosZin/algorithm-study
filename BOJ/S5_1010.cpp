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
//N���� ����Ʈ ������ŭ �ٸ��� ���´�
//�߿��� ������ <�ٸ����� ���� ������ �� ����!!
//��, X = {1, 2, 3, 4} Y = {1, 2, 3, 4, 5, 6, 7} �� ��,
//1<= f(1) < f(2) < f(3) < f(4) <= 7�� ������ �ְ�
//���� 7C4��� ���� �߻���!
//
//=> mCn�� ���ϴ� ���� �ٽ���~!*/