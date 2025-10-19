// 19. Hollow Hourglass Pattern
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size (half-height) of the hourglass: ";
    cin >> size;

    // Upper half
    for (int i = size; i >= 1; i--) {
        for (int j = 1; j <= size - i; j++) cout << " ";
        for (int k = 1; k <= i; k++) {
            // Print star only for first/last row or first/last char
            if (i == size || k == 1 || k == i)
                cout << "* ";
            else
                cout << "  "; // Print space inside
        }
        cout << endl;
    }
    // Lower half
    for (int i = 2; i <= size; i++) {
        for (int j = 1; j <= size - i; j++) cout << " ";
        for (int k = 1; k <= i; k++) {
            // Print star only for first/last row or first/last char
            if (i == size || k == 1 || k == i)
                cout << "* ";
            else
                cout << "  "; // Print space inside
        }
        cout << endl;
    }
    return 0;
}