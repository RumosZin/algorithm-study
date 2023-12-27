//#include <iostream>
//#include <vector>
//#include <cmath>
//#define MAX 22222222
//
//using namespace std;
//
//
//struct House {
//	int r, c;
//};
//struct Chicken {
//	int r, c;
//	bool visited;
//};
//
//int N, M;
//int mincitydist = MAX;
//
//vector<House> house;
//vector<Chicken> chicken;
//
//void calculateDistance() {
//	// 선택된 M개의 치킨집과의 거리 중 최솟값 구하기
//	int cityDistance = 0;
//	for (int i = 0; i < house.size(); i++) {
//		int minHouseDistance = MAX;
//		for (int j = 0; j < chicken.size(); j++) {
//			if (chicken[j].visited) {
//				int houseDistance = abs(house[i].r - chicken[j].r) + abs(house[i].c - chicken[j].c);
//				if (houseDistance < minHouseDistance) {
//					minHouseDistance = houseDistance;
//				}
//			}
//		}
//		cityDistance += minHouseDistance;
//	}
//	if (cityDistance < mincitydist) mincitydist = cityDistance;
//}
//
//void selectChicken(int index, int count) { // dfs + 조합
//	// 폐업시키지 않을 치킨집 최대 M개 고르기
//	if (count == M) calculateDistance();
//	for (int i = index; i < chicken.size(); i++) {
//		if (!chicken[i].visited) {
//			chicken[i].visited = true;
//			selectChicken(i, count + 1);
//			chicken[i].visited = false;
//		}
//	}
//
//}
//
//int main() {
//	cin >> N >> M;
//	int flag;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> flag;
//			if (flag == 1) house.push_back({ i, j });
//			else if (flag == 2) chicken.push_back({ i, j, false });
//		}
//	}
//
//	selectChicken(0, 0);
//	cout << mincitydist;
//}