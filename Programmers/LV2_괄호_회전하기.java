import java.lang.*;
import java.util.*;

// 2:19 - 2:56

class Solution {
    public int solution(String s) {
        int answer = 0;
        Stack<Character> stack = new Stack<>();
        Map<Character, Character> pair = new HashMap<>();
        Map<Character, Character> close = new HashMap<>();
        
        pair.put('[', ']'); close.put(']', '[');
        pair.put('{', '}'); close.put('}', '{');
        pair.put('(', ')'); close.put(')', '(');
        
        if(s.length() == 1) return 0;
        
        for(int i = 0; i < s.length(); i++) { // i는 시작 인덱스
            boolean ok = true;
            for(int j = i; j < i + s.length(); j++) {
                int idx = j % s.length();
                if(pair.containsKey(s.charAt(idx))) { stack.push(s.charAt(idx)); }
                else if(close.containsKey(s.charAt(idx))) {
                    if(stack.size() > 0 && stack.peek() == close.get(s.charAt(idx))) stack.pop();
                    else { ok = false; }
                }
                if(!ok) break;
            }
            if(ok && stack.size() == 0) answer++; 
            while(!stack.empty()) stack.pop();
        }
        
        return answer;
    }
}