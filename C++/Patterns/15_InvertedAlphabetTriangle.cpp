// 15. Inverted Alphabet Triangle
#include <iostream>
using namespace std;

int main() {
    int height;
    cout << "Enter the height of the triangle: ";
    cin >> height;

    for (int i = height; i >= 1; i--) {
        char ch = 'A';
        for (int j = 1; j <= i; j++) {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
    return 0;
}
