#include <iostream>

using namespace std;

int N = 20; // max bit
int M; // command
int S = 0; // empty set S

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    cin >> M;

    string command;
    int x;

    for(int i = 0; i < M; i++) {
        cin >> command;

        if(command == "add") {
            cin >> x;
            S |= (1 << --x);
        }
        else if(command == "remove") {
            cin >> x;
            S &= ~(1 << --x);
        }
        else if(command == "check") {
            cin >> x;
            if((S & (1 << --x))) cout << "1\n";
            else cout << "0\n";

        }
        else if(command == "toggle") {
            cin >> x;
            S ^= (1 << --x);
        }
        else if(command == "all") {
            S = (1 << N) - 1;
        }
        else if(command == "empty") {
            S = 0;
        }
    }

    return 0;
}