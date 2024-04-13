#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>;

using namespace std;

int N, M; // height, width
int board[8][8];
int visited[8][8];

int virus_safety = 0;
int wall_count = 0;

typedef struct location {
    int row, col;
};

vector<location> spaces;
vector<location> viruses;

queue<location> q;

vector<int> safety;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int row, int col) {

    // initialize
    q.push({ row, col });
    visited[row][col] = 1;

    while (!q.empty()) {
        int row = q.front().row;
        int col = q.front().col;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int next_row = row + dx[d];
            int next_col = col + dy[d];

            if (next_row >= 0 && next_row < N
                && next_col >= 0 && next_col < M
                && board[next_row][next_col] != 1
                && visited[next_row][next_col] != 1) {
                q.push({ next_row, next_col });
                visited[next_row][next_col] = 1;
            }
        }

    }
}

int main() {

    // input
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                viruses.push_back({ i, j });
            }
            else if (board[i][j] == 0) {
                spaces.push_back({ i, j });
            }
            else if (board[i][j] == 1) wall_count++;
        }
    }

    // choose wall position 3
    vector<int> temp;
    for (int i = 0; i < 3; i++) { temp.push_back(1); }
    for (int i = 0; i < spaces.size() - 3; i++) { temp.push_back(0); }
    sort(temp.begin(), temp.end());

    do {
        // make 3 walls
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == 1) { board[spaces[i].row][spaces[i].col] = 1; }
        }

        // viruses;
        for (int i = 0; i < viruses.size(); i++) {
            bfs(viruses[i].row, viruses[i].col);
        }

        // count safety_area
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] == 1) virus_safety++;
            }
        }

        safety.push_back(N * M - (wall_count + 3) - virus_safety);

        // initialize
        memset(visited, 0, sizeof(visited));
        virus_safety = 0;

        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == 1) { board[spaces[i].row][spaces[i].col] = 0; }
        }
    } while (next_permutation(temp.begin(), temp.end()));

    // find max safety area size
    sort(safety.begin(), safety.end());
    cout << safety[safety.size() - 1] << "\n";
}