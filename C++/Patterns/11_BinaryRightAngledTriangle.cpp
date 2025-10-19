// 11. Binary Right-Angled Triangle
#include <iostream>
using namespace std;
int main() {
    int height;
    cout << "Enter the height of the triangle: ";
    cin >> height;
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= i; j++) {
            // (i+j) is even for 1, odd for 0
            if ((i + j) % 2 == 0) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return 0;
}