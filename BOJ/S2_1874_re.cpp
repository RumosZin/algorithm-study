#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N; 
    cin >> N;
    vector<int> order(N);
    vector<char> answer;
    stack<int> st;
    for(int i = 0; i < N; i++) cin >> order[i];

    int idx = 0;
    for(int i = 1; i <= N; i++) {
        st.push(i); answer.push_back('+');
        while(!st.empty() && st.top() == order[idx]) {
            answer.push_back('-');
            st.pop(); idx++;
        }
    }

    if(!st.empty()) 
        cout << "NO"; return 0;

    for(char c : answer) cout << c << "\n";

    return 0;
}