#include <bits/stdc++.h>
using namespace std;

void print16(int n) {
    char ch = 'A';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << ch << " ";
        }
        cout << endl;
        ch++;
    }
}

int main() {
    int n;
    cin >> n;
    print16(n);
    return 0;
}