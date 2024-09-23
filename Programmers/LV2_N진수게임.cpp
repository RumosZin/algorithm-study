#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 9:25 1차 : 10:24 한번에 맞음!!

vector<char> alpha = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                  'A', 'B', 'C', 'D', 'E', 'F'};

string over(int n, int total) { // 진법, m * t(전체)
    string str = "0"; int soo = 1; int num = 1;
    
    while(str.size() < total) {
        string temp = ""; num = soo;
        
        while(num != 0) { 
            temp += alpha[num % n]; num /= n;    
        }
        reverse(temp.begin(), temp.end());
        str += temp; soo++;
    }
    
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = ""; string str = "";
    str = over(n, m * t);
    
    int num = 0;
    while(t > 0) { answer += str[m * num + (p - 1)]; num++; t--; }
    
    return answer;
}