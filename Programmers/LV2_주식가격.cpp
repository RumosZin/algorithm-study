#include <string>
#include <vector>
#include <iostream>
#include <stack>

// 7:04 - 7:25

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int, int>> st; 
    
    for(int i = 0; i < prices.size(); i++) {
        int p = prices[i];
        if(st.empty() || p >= st.top().first) st.push(make_pair(p, i));
        
        else {
            while(!st.empty() && p < st.top().first) {
                answer[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push(make_pair(p, i));
            
        }    
    }
    
    while(!st.empty()) {
        answer[st.top().second] = prices.size() - st.top().second - 1;
        st.pop();
    }
    
    return answer;
}