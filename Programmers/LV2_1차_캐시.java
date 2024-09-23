import java.lang.*;
import java.util.*;

// 7:44 - 8:08 70
// 8:20 100
class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        List<String> order = new LinkedList<>();
        Set<String> cache = new HashSet<>();
        
        for(String city : cities) {
            city = city.toLowerCase();
            if(cache.contains(city)) {
                answer += 1;
                order.remove(city); order.add(city);
            }
            else if(cache.size() == cacheSize) {
                if(cacheSize == 0) { answer += 5; continue; }
                cache.remove(order.get(0)); cache.add(city);
                order.remove(order.get(0)); order.add(city);
                answer += 5;
            }
            else {
                cache.add(city); order.add(city); 
                answer += 5;
            }
        }
        return answer;
    }
}