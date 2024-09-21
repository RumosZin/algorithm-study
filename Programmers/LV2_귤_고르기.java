import java.lang.*;
import java.util.*;

// 12:59 - 1:20

class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        Map<Integer, Integer> tan = new HashMap<>();
        
        for(int tanger : tangerine) {
            if(!tan.containsKey(tanger)) tan.put(tanger, 1);
            else tan.replace(tanger, tan.get(tanger) + 1);
        }
        
        List<Map.Entry<Integer, Integer>> entryTan = new LinkedList<>(tan.entrySet());
        entryTan.sort(((o1, o2) -> o2.getValue() - o1.getValue()));
        
        int total = 0;
        for(Map.Entry<Integer, Integer> entry : entryTan) {
            if(total < k) {
                total += entry.getValue();
                answer++;
            } else break;
        }
        
        return answer;
    }
}