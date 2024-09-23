#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 11:55

string n_to_k(int n, int k) {
    string str = ""; 
    while(n > 0) { str += to_string(n % k); n /= k;}
    reverse(str.begin(), str.end());
    
    return str;
}

bool is_prime(string input) {
    if(input.empty()) return false;
    long long n = stoll(input);
    if(n <= 1) return false; 
    if(n == 2 || n == 3) return true;

    bool its_prime = true;
    for(long long i = 2; i <= sqrt(n); i++) { 
        if(n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string conum = n_to_k(n, k);
    stringstream ss(conum); string subst = ""; vector<string> v;
    
    while(getline(ss, subst, '0')) {
        if(is_prime(subst)) { answer++; }
    }
    return answer;
}