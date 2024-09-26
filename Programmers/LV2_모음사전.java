import java.lang.*;
import java.util.*;

// 4:39
class Solution {
    char[] alphabet = {'A', 'E', 'I', 'O', 'U'};
    int answer = 0;
    List<String> list = new ArrayList<>();
    
    public int solution(String word) {
      
        for(int i = 0; i < 5; i++) { // aeiou에 대해 모두 시행
            dfs("", 0);
        }
        
        for(int i = 0; i < list.size(); i++) {
            if(list.get(i).equals(word)) {
                answer = i; break;
            }
        }
        return answer;
    }
    
    public void dfs(String w, int length) {
        list.add(w);
        if(length == 5) return;
        for(int i = 0; i < 5; i++) {
            dfs(w + alphabet[i], length + 1);
        }
    }
}