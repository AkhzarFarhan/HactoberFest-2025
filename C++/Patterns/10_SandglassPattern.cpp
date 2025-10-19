// 10. Sandglass Pattern
#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "Enter the size (half-height) of the sandglass: ";
    cin >> size;
    // Upper half (inverted pyramid)
    for (int i = size; i >= 1; i--) {
        for (int j = 1; j <= size - i; j++) cout << "  ";
        for (int k = 1; k <= 2 * i - 1; k++) cout << "* ";
        cout << endl;
    }
    // Lower half (pyramid)
    for (int i = 2; i <= size; i++) {
        for (int j = 1; j <= size - i; j++) cout << "  ";
        for (int k = 1; k <= 2 * i - 1; k++) cout << "* ";
        cout << endl;
    }
    return 0;
}