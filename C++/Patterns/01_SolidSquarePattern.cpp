// 1. Solid Square Pattern
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the square: ";
    cin >> size;

    // Outer loop for rows
    for (int i = 0; i < size; i++) {
        // Inner loop for columns
        for (int j = 0; j < size; j++) {
            cout << "* ";
        }
        // Move to the next line after each row
        cout << endl;
    }
    return 0;
}