#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    stack<pair<int, int>> st;
    
    for(int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        if(st.empty() || st.top().first > num) {
            st.push(make_pair(num, i));
        }
        else {
            while(!st.empty() && st.top().first < num) {
                int value = st.top().first;
                int index = st.top().second;
                st.pop();
                answer[index] = num;
            }
            st.push(make_pair(num, i));
        }
    }
    
    while(!st.empty()) {
        int val = st.top().first;
        int idx = st.top().second;
        st.pop();
        answer[idx] = -1;
    }
    return answer;
}