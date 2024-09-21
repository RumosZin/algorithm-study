import java.util.*; // 이거 개 굿인듯

// 9:42 - 10:01

class Solution {
    public int solution(int[] arr) {
        int answer = 0;
        
        Arrays.sort(arr);
        
        for(int i = 0; i < arr.length - 1; i++){
            int num = gcd(arr[i + 1], arr[i]); // 큰 값이 앞으로
            arr[i + 1] = (arr[i] * arr[i + 1]) / num;
        }        
        return arr[arr.length - 1];
    }
    
    public static int gcd(int n1, int n2) {
        if(n1 % n2 == 0) return n2;
        return gcd(n2, n1 % n2);
    }
}