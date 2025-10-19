// 18. Reverse Alphabet Triangle
#include <iostream>
using namespace std;

int main() {
    int height;
    cout << "Enter the height of the triangle: ";
    cin >> height;

    for (int i = 1; i <= height; i++) {
        // Start from 'A' + height - i
        char ch = 'A' + height - i;
        for (int j = 1; j <= i; j++) {
            cout << ch << " ";
            ch++; // Increment letter
        }
        cout << endl;
    }
    return 0;
}