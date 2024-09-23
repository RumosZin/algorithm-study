import java.lang.*;
import java.util.*;

// 2:45 - 3:21

class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        
        Map<String, Integer> wants = new HashMap<>();
        for(int i = 0; i < want.length; i++) { wants.put(want[i], number[i]); }
        
        Map<String, Integer> count = new HashMap<>();
        for(int i = 0; i < 10; i++) { count.put(discount[i], count.getOrDefault(discount[i], 0) + 1); }
        
        int start = 0; int end = 9; 
        for(int i = end; i < discount.length; i++) {
            boolean enter = true;
            for(int j = 0; j < want.length; j++) {         
                String product = want[j]; Integer num = wants.get(product);
                if(count.getOrDefault(product, 0) == 0 
                  || count.get(product) < num) { enter = false; break; }    
            }
            
            if(enter) answer++;
            
            count.put(discount[start], count.getOrDefault(discount[start], 0) - 1); start++;
            if(end < discount.length - 1) { end++; count.put(discount[end], count.getOrDefault(discount[end], 0) + 1); 
            }
        }
        return answer;
    }
}