// 6. Inverted Half Pyramid (Numbers)
#include <iostream>
using namespace std;
int main() {
    int height;
    cout << "Enter the height of the pyramid: ";
    cin >> height;
    for (int i = height; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}