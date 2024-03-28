//#include <iostream>
//
//using namespace std;
//
//// pow를 쓰면 너무 오래 걸림
//// 일의 자리만 있으면 %10 하는데 문제 없음
//// b만큼 곱하는데 일의 자리만 얻어내서 곱하면 됨!
//// 주의! 나머지 문제의 경우 항상 <나누어 떨어지는> 경우를 고려해야 함!
//
//int temp; //  모든 수의 0승은 1
//int T, a, b;
//
//int main()
//{
//    cin >> T;
//    for (int i = 0; i < T; i++) {
//        temp = 1;
//        cin >> a >> b; // 띄어쓰기 기준으로 a, b 입력받기
//        for (int j = 0; j < b; j++) { 
//            temp = (temp * a) % 10; // 일의 자리만 얻어내서 계산 가능함
//        }
//
//        if (temp == 0) cout << "10" << "\n";
//        else cout << temp << "\n";
//
//    }
//}