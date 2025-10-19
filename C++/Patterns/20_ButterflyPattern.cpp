// 20. Butterfly Pattern
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size (half-height) of the butterfly: ";
    cin >> size;

    // Upper half
    for (int i = 1; i <= size; i++) {
        // Left stars
        for (int j = 1; j <= i; j++) cout << "* ";
        // Spaces in middle
        for (int k = 1; k <= 2 * (size - i); k++) cout << "  ";
        // Right stars
        for (int j = 1; j <= i; j++) cout << "* ";
        cout << endl;
    }
    // Lower half
    for (int i = size; i >= 1; i--) {
        // Left stars
        for (int j = 1; j <= i; j++) cout << "* ";
        // Spaces in middle
        for (int k = 1; k <= 2 * (size - i); k++) cout << "  ";
        // Right stars
        for (int j = 1; j <= i; j++) cout << "* ";
        cout << endl;
    }
    return 0;
}