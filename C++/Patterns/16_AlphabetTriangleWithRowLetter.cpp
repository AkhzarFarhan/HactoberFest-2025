// 16. Alphabet Triangle with Row Letter
#include <iostream>
using namespace std;

int main() {
    int height;
    cout << "Enter the height of the triangle: ";
    cin >> height;

    for (int i = 1; i <= height; i++) {
        // 'A' + i - 1 gives the letter for the row
        char ch = 'A' + i - 1; 
        for (int j = 1; j <= i; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}