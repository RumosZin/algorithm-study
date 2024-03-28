//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//// 패턴으로 뭘 쳐야 그 결과가 나오는지 출력하는 문제
//vector<char> pattern;
//
//
//int main() {
//	int T;
//	cin >> T;
//	for (int i = 0; i < T; i++) {
//		string temp;
//		cin >> temp;
//		for (int j = 0; j < temp.length(); j++) { // 파일 이름의 길이는 최대 50 - length 뒤에 괄호 붙여야돼
//			if (i == 0) { // 첫번째 string을 입력받는 경우 전부 집어넣기
//				//cout << temp[j] << "\n";
//				//if (temp[j] == '\n') break;
//				pattern.push_back(temp[j]);
//			}
//			else { // 두번째부터 비교
//				//cout << pattern[j] << " " << temp[j] << "\n";
//				if (pattern[j] == temp[j]) { // 같으면 pattern이 맞음
//					continue;
//				}
//				else { // 다르면 pattern이 아님
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