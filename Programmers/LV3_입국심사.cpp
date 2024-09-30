#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long max_time = (long long)times.back() * n;
    
    long long start = 1; long long end = max_time;
    while(start <= end) {
        long long mid = start + (end - start) / 2;
        long long exe = 0;
        for(long long time : times) exe += mid / time;
        
        if(exe >= n) {
            end = mid - 1;
            answer = mid;
        }
        else start = mid + 1;
    }
    return answer;
}