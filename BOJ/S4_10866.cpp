#include <iostream>
#include <deque>

using namespace std;

int N;

int main() {
    // input
    cin >> N;
    
    deque<int> dq;

    for(int i = 0; i < N; i++) {
        string cmd;
        int value;
        cin >> cmd;
        if(cmd == "push_back") {
            cin >> value;
            dq.push_back(value);
        }
        else if(cmd == "push_front") {
            cin >> value;
            dq.push_front(value);
        }
        else if(cmd == "front") {
            if(dq.size() == 0) cout << "-1\n";
            else cout << dq.front() << "\n";
        }
        else if(cmd == "back") {
            if(dq.size() == 0) cout << "-1\n";
            else cout << dq.back() << "\n";
        }
        else if(cmd == "size") cout << dq.size() << "\n";
        else if(cmd == "empty") cout << dq.empty() << "\n";
        else if(cmd == "pop_front") {
            if(dq.size() == 0) cout << "-1\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if(cmd == "pop_back") {
            if(dq.size() == 0) cout << "-1\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
    }
}