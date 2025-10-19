// 21. Hollow Square Pattern
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the square: ";
    cin >> size;

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            // Print star only for first/last row or first/last column
            if (i == 1 || i == size || j == 1 || j == size)
                cout << "* ";
            else
                cout << "  "; // Print space inside
        }
        cout << endl;
    }
    return 0;
}