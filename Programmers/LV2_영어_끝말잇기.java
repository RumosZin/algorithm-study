import java.util.*;
import java.lang.*;

// 10:06 - 10:25 
// 30점, 엣지 케이스 확인

class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = {};
        List<Integer> list = new ArrayList<>();
        Map<String, Integer> dictionary = new HashMap<>();
        dictionary.put(words[0], 1);
        
        for(int i = 1; i < words.length; i++) {
            // 겹치는 단어인지 확인
            if(!dictionary.containsKey(words[i])
              && words[i - 1].charAt(words[i - 1].length() - 1) == words[i].charAt(0)
              && words[i].length() != 1) 
                dictionary.put(words[i], 1);          
            else {
                list.add(i % n + 1);
                list.add(i / n + 1);  
                break;
            } 
        }
        
        if(list.size() == 0) {
            list.add(0); list.add(0);
        }
        return list.stream().mapToInt(integer -> integer).toArray();
    }
}