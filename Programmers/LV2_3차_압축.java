import java.lang.*;
import java.util.*;

// 3:01 - 4:07 : 풀이 참고함...
class Solution {

    public int[] solution(String msg) {
        Map<String, Integer> dictionary = new HashMap<>();
        List<Integer> ans = new ArrayList<>();
        
        int index = init(dictionary);
        
        for(int i = 0; i < msg.length(); i++) {
            String word = "";
            while(i < msg.length() && dictionary.containsKey(word + msg.charAt(i))) {
                word += msg.charAt(i);
                i++;
            }
            
            ans.add(dictionary.get(word));
            if(i < msg.length()) {
                dictionary.put(word + msg.charAt(i), index);
                index++; i--;
            }
        }
        
        return ans.stream().mapToInt(integer -> integer).toArray();
    }
    
    private int init(Map<String, Integer> map) {
        int index = 1;
        for(char ch = 'A'; ch <= 'Z'; ch++) { map.put(String.valueOf(ch), index++); }
        
        return index;
    }
}