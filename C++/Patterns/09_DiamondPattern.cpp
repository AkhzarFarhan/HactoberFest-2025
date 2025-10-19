// 9. Diamond Pattern
#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "Enter the size (half-height) of the diamond: ";
    cin >> size;
    // Upper half
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size - i; j++) cout << "  ";
        for (int k = 1; k <= 2 * i - 1; k++) cout << "* ";
        cout << endl;
    }
    // Lower half
    for (int i = size - 1; i >= 1; i--) {
        for (int j = 1; j <= size - i; j++) cout << "  ";
        for (int k = 1; k <= 2 * i - 1; k++) cout << "* ";
        cout << endl;
    }
    return 0;
}
