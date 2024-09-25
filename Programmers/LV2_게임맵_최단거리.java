import java.util.*;
import java.lang.*;

// 1:53 - 2:29

class Solution {
    int[] dx = {0, 0, 1, -1};
    int[] dy = {1, -1, 0, 0};
    
    class location {
        int r, c, d;
        
        public location(int r, int c, int d) {
            this.r = r; this.c = c; this.d = d;
        }
    }
    
    public int solution(int[][] maps) {
        int answer = -1; int r = maps.length; int c = maps[0].length;
        int[][] dist = new int[r][c]; 
        int[][] visited = new int[r][c]; 
        Queue<location> q = new LinkedList<>();
        
        dist[0][0] = 1;
        visited[0][0] = 1;
        q.add(new location(0, 0, 1)); 
        
        // bfs
        int num = 0;
        while(!q.isEmpty()) {
            location loc = q.poll();
            int c_r = loc.r; int c_c = loc.c; int c_d = loc.d;
            
            // stop condition
            if(c_r == r - 1 && c_c == c - 1) {
                answer = c_d;
                break;
            }
            
            for(int d = 0; d < 4; d++) {
                int next_r = c_r + dx[d]; int next_c = c_c + dy[d];
                if(next_r < 0 || next_r >= r || next_c < 0 || next_c >= c
                  || visited[next_r][next_c] == 1
                  || maps[next_r][next_c] == 0) continue;
                
                q.add(new location(next_r, next_c, c_d + 1));
                dist[next_r][next_c] = c_d + 1;
                visited[next_r][next_c] = 1;
            }
        }
        return answer;
    }
}

