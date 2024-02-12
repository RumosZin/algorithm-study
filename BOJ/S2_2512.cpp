#include<iostream>

using namespace std;

int values[10001];

int search(int n, int m, int standard) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (values[i] <= standard) {
            result += values[i];
        }
        else {
            result += standard;
        }
    }
    if (result <= m) {
        return 1;
    }
    else {
        return 0;
    }
}

int binarysearch(int max, int n, int m) {
    int low = 0, high = max;
    int standard = 0;
    int result = 0;
    while (low <= high) {
        //cout << low << " " << high << endl;
        standard = (high + low) / 2;
        if (search(n, m, standard) == 1) {
            result = standard;
            low = standard + 1;
        }
        else {
            high = standard - 1;
        }
    }
    return result;
}

int main() {
    int n, m;
    int max = 0;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> values[i];
        if (values[i] > max) { max = values[i]; }
        sum += values[i];
    }
    cin >> m;
    if (sum <= m) {
        cout << max;
    }
    else {
        cout << binarysearch(max, n, m);
    }
}