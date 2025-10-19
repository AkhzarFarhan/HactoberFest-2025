// 12. Number Hourglass Pattern
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size (half-height) of the hourglass: ";
    cin >> size;

    // Upper half
    for (int i = size; i >= 1; i--) {
        // Print spaces
        for (int j = 1; j <= size - i; j++) {
            cout << " ";
        }
        // Print numbers
        for (int k = 1; k <= i; k++) {
            cout << k << " ";
        }
        cout << endl;
    }
    // Lower half
    for (int i = 2; i <= size; i++) {
        // Print spaces
        for (int j = 1; j <= size - i; j++) {
            cout << " ";
        }
        // Print numbers
        for (int k = 1; k <= i; k++) {
            cout << k << " ";
        }
        cout << endl;
    }
    return 0;
}