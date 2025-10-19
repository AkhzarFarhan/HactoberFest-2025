// 2. Right-Angled Triangle (Half Pyramid)
#include <iostream>
using namespace std;

int main() {
    int height;
    cout << "Enter the height of the triangle: ";
    cin >> height;

    // Outer loop for rows
    for (int i = 1; i <= height; i++) {
        // Inner loop for columns
        // Prints '*' i times
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        // Move to the next line after each row
        cout << endl;
    }
    return 0;
}