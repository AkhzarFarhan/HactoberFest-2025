// 8. Inverted Centered Pyramid
#include <iostream>
using namespace std;
int main() {
    int height;
    cout << "Enter the height of the pyramid: ";
    cin >> height;
    for (int i = height; i >= 1; i--) {
        // Print spaces
        for (int j = 1; j <= height - i; j++) {
            cout << "  ";
        }
        // Print stars
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}