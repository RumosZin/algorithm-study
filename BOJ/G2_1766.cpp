#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> problems;
vector<int> needed;
string answer = "";

void un_needed(int curr) {
    for(int pb : problems[curr]) needed[pb]--;
}

void BFS() {
    // needed less, priority high
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= N; i++) { if(needed[i] == 0) pq.push(i); }

    // BFS
    while(!pq.empty()) {
        int curr = pq.top(); pq.pop();
        un_needed(curr);
        answer += to_string(curr); answer += " ";

        for(int pb : problems[curr]) if(needed[pb] == 0) pq.push(pb);
    }
}

int main() {
    // input
    cin >> N >> M;
    problems.resize(N + 1); needed.resize(N + 1);
    
    for(int i = 0; i < N; i++) problems[i + 1] = vector<int>();
    for(int i = 0; i < M; i++) {
        int fp, sp; cin >> fp >> sp;
        problems[fp].push_back(sp); needed[sp]++;
    }

    // BFS
    BFS();

    cout << answer; return 0;
}