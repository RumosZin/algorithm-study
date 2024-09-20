import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;

class Solution {
    
    public int[] solution(String today, String[] terms, String[] privacies) {
        // int[] answer = {};
        List<Integer> answer = new ArrayList<>();
        int today_days = days(today);
        Map<String, Integer> termMap = new HashMap<>();
        
        // 약관-일수 매핑
        for(String s : terms) {
            String[] term = s.split(" ");
            termMap.put(term[0], Integer.parseInt(term[1]) * 28);
        }
        
        for(int i = 0; i < privacies.length; i++) {
            String[] privacy = privacies[i].split(" ");
            
            if(days(privacy[0]) + termMap.get(privacy[1]) <= today_days)
                answer.add(i + 1);
        }
        
        return answer.stream().mapToInt(integer -> integer).toArray();
    }
    
    public int days(String input) {
        String[] date = input.split("\\.");
        int yy = Integer.parseInt(date[0]);
        int mm = Integer.parseInt(date[1]);
        int dd = Integer.parseInt(date[2]);
        
        return (yy - 2000) * 12 * 28 + mm * 28 + dd;
    }
}