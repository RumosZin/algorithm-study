import java.lang.*;
import java.util.*;

// 3:33 - 3:53

class Solution {
    public int[] solution(int n, long left, long right) {
        int[] answer = {};
        
        List<Long> list = new ArrayList<>();
        for(long num = left; num <= right; num++) { list.add(number(n, num)); }
        
        return list.stream().mapToInt(Long::intValue).toArray();
    }
    
    public static long number(int n, long num) {
        return Math.max(num / n, num % n) + 1;
    }
}