//#include <iostream>
//
//using namespace std;
//
//int count;
//int num = 2;
//int total_num = 1;
//int input;
//
//int main() {
//	cin >> input;
//	bool find = false;
//	total_num = 1;
//	while (!find) {
//		
//		if (total_num < input) {
//			total_num += num;
//			num++;
//		}
//		else {
//			find = true;
//			num--;
//		}
//	}
//	//cout << total_num << " " << num;
//	
//	// input�� 14�� ��
//	// num���� 5�� �ִ� ��Ȳ
//	if (num % 2 == 1) { // num�� Ȧ���̸� ���� 6�� ��Ȳ
//		total_num -= num; // total_num = 10
//		int increase_num = input - total_num; // 14 - 10 = 4
//		int decrease_num = (num + 1) - increase_num; // 2
//		cout << decrease_num << "/" << increase_num;
//	}
//	else { 
//		total_num -= num;
//		int decrease_num = input - total_num;
//		int increase_num = (num + 1) - decrease_num;
//		cout << decrease_num << "/" << increase_num;
//
//	}
//
//}