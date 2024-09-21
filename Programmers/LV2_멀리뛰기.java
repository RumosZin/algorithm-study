import java.util.List;
import java.util.ArrayList;

class Solution {
    public long solution(int n) {
        long answer = 0;
        List<Integer> dp = new ArrayList<>();
        
        dp.add(1); dp.add(1);
        for(int i = 2; i <= n; i++) {
            dp.add((dp.get(i - 1) + dp.get(i - 2)) % 1234567);
        }
        
        return dp.get(n);
    }
}