// 13. Continuous Number Triangle
#include <iostream>
using namespace std;

int main() {
    int height;
    cout << "Enter the height of the triangle: ";
    cin >> height;

    int num = 1; // Start with 1
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= i; j++) {
            cout << num << " ";
            num++; // Increment the number
        }
        cout << endl;
    }
    return 0;
}