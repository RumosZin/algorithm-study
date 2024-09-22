import java.lang.*;
import java.util.*;

// 7:23 - 7:39

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> list = new ArrayList<>();
        int[] left_days = new int[progresses.length];
        
        for(int i = 0; i < progresses.length; i++) {
            int day = (100 - progresses[i]) / speeds[i];
            int left = (100 - progresses[i]) % speeds[i] == 0 ? 0 : 1; 
            left_days[i] = day + left;
        }

        int cur_max = left_days[0]; int count = 0;
        for(int i = 0; i < left_days.length; i++) { 
            if(cur_max >= left_days[i]) count++;
            else if(cur_max < left_days[i]) {
                cur_max = left_days[i]; list.add(count); count = 1;
            }
        }
        list.add(count);
        
        return list.stream().mapToInt(integer -> integer).toArray();
    }
}