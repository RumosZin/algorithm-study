#include <string>
#include <vector>
#include <map>

using namespace std;

// 3:39 - 4:08, 엣지 찾기 4:18

int dx[4] = { 0, 0, 1, -1 }; // e w s n
int dy[4] = { 1, -1, 0, 0 };

map<char, int> m;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    vector<vector<char>> rec(park.size(), vector<char>(park[0].size(), ' '));
    m['E'] = 0; m['W'] = 1; m['S'] = 2; m['N'] = 3;
    int r = park.size(); int c = park[0].size();
    int s_r, s_c;
    
    // 공원 : 이차원 배열
    for(int i = 0; i < park.size(); i++) {
        for(int j = 0; j < park[i].size(); j++) {
            if(park[i][j] == 'S') { s_r = i; s_c = j; }
            rec[i][j] = park[i][j];
        }
    }
    
    // 산책 : 조건 확인
    for(string cmd : routes) {
        char dir = cmd.substr(0, cmd.find(' '))[0];
        int len = stoi(cmd.substr(cmd.find(' ') + 1));
        
        int next_r, next_c;
        bool is_out = false;
        bool is_obstacle = false;
        for(int i = 0; i <= len; i++) {
            next_r = s_r + dx[m[dir]] * i; next_c = s_c + dy[m[dir]] * i;
            if(next_r >= r || next_r < 0
              || next_c >= c || next_c < 0) { is_out = true; break; }
            if(rec[next_r][next_c] == 'X') is_obstacle = true;
        }
        if(is_obstacle || is_out) continue;
        else { s_r = next_r; s_c = next_c; }
    }
    
    return {s_r, s_c};
}