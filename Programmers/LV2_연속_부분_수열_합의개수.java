import java.util.*;
import java.lang.*;

class Solution {
    public int solution(int[] elements) {
        int answer = 0;
        int length = elements.length;
        Set<Integer> num = new HashSet<>();
        
        for(int i = 0; i < length; i++) {
            int temp = 0;
            for(int j = i; j < i + length; j++) {
                temp += elements[j % length];
                num.add(temp);
            }
        }
        
        answer = num.size();
        
        return answer;
    }
}