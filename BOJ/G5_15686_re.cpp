#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#define MAX 987654321

using namespace std; // 3:55 - 4:50

int N, M;
int arr[51][51];
vector<pair<int, int>> cities; // 1도시들 위치 쌍 기억
vector<pair<int, int>> chickens; // 2치킨집들 위치 쌍 기억
int answer = 0; // 구한 쌍에 대해 모든 치킨거리 기억
vector<int> correct;

int main() {
    // input
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) cities.push_back({i, j});
            if(arr[i][j] == 2) chickens.push_back({i, j});
        }
    }

    // 치킨집들 중에서 M개의 치킨집만 고르기 : 조합, next_permutation
    vector<pair<int, int>> picked;
    // 1. 보조 수열 만들기 : M개만큼 0을 넣는다!!!
    vector<int> tmp(chickens.size(), 1);
    for(int i = 0; i < M; i++) tmp[i] = 0;
    
    // 2. do-while next_permutation
    do {
        answer = 0;
        // picked에 대해서 집과 picked의 치킨 거리 계산
        // 집 하나 - 모든 치킨거리 구하기 - 최솟값 더하기
        for(int i = 0; i < cities.size(); i++) {
            int dist = MAX;
            for(int j = 0; j < tmp.size(); j++) {
                if(tmp[j] != 0) continue; 
                dist = min(dist, abs(cities[i].first - chickens[j].first) + abs(cities[i].second - chickens[j].second));
            }
            answer += dist;
        }
         
        correct.push_back(answer);
        
    } while(next_permutation(tmp.begin(), tmp.end()));

    sort(correct.begin(), correct.end());

    cout << correct[0];
    return 0;
}