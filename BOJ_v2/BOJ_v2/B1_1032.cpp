//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//// �������� �� �ľ� �� ����� �������� ����ϴ� ����
//vector<char> pattern;
//
//
//int main() {
//	int T;
//	cin >> T;
//	for (int i = 0; i < T; i++) {
//		string temp;
//		cin >> temp;
//		for (int j = 0; j < temp.length(); j++) { // ���� �̸��� ���̴� �ִ� 50 - length �ڿ� ��ȣ �ٿ��ߵ�
//			if (i == 0) { // ù��° string�� �Է¹޴� ��� ���� ����ֱ�
//				//cout << temp[j] << "\n";
//				//if (temp[j] == '\n') break;
//				pattern.push_back(temp[j]);
//			}
//			else { // �ι�°���� ��
//				//cout << pattern[j] << " " << temp[j] << "\n";
//				if (pattern[j] == temp[j]) { // ������ pattern�� ����
//					continue;
//				}
//				else { // �ٸ��� pattern�� �ƴ�
//					pattern[j] = '?';
//				}
//
//			}
//		}
//
//	}
//
//	for (int i = 0; i < pattern.size(); i++) {
//		cout << pattern[i];
//	}
//	//cout << pattern[0];
//}