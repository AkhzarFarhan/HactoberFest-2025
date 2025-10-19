// 14. Alphabet Right-Angled Triangle
#include <iostream>
using namespace std;

int main() {
    int height;
    cout << "Enter the height of the triangle: ";
    cin >> height;

    for (int i = 1; i <= height; i++) {
        char ch = 'A'; // Start with 'A' for each row
        for (int j = 1; j <= i; j++) {
            cout << ch << " ";
            ch++; // Go to next letter
        }
        cout << endl;
    }
    return 0;
}
