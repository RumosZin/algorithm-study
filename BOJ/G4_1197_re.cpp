#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int vertex, E;
int answer = 0;
vector<pair<int, pair<int, int>>> v; 
int parent[10001];
// 앞의 int가 무조건 비용이어야 한다 : 크루스칼 알고리즘은 모든 간선을 가중치를 기준으로 오룸차순!

int find_parent(int x) {
    if(parent[x] == x) return x;
    else return parent[x] = find_parent(parent[x]);
}

void union_find(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);

    parent[y] = x;
}

bool same_parent(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);
    if(x == y) return true;
    else return false;
}

int main() {
    cin >> vertex >> E;
    int a, b, w;
    for(int i = 0; i < E; i++) {
        cin >> a >> b >> w;
        v.push_back({w, {a, b}});
    }

    sort(v.begin(), v.end()); // 크루스칼 알고리즘은 가중치 오름차순!

    // 사이클이 형성되지 않아야 하므로 parent가 같으면 안되는 것을 이용한다
    for(int i = 1; i <= vertex; i++) parent[i] = i; 
    for(int i = 0; i < v.size(); i++) { // 가중치 최소 노드부터!
        if(!same_parent(v[i].second.first, v[i].second.second)) { // 사이클이 없으면
            union_find(v[i].second.first, v[i].second.second);
            answer += v[i].first; // 비용 추가
        }
    }

    cout << answer;

    return 0;
}