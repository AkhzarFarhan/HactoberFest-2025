// 17. Palindromic Alphabet Pyramid
#include <iostream>
using namespace std;

int main() {
    int height;
    cout << "Enter the height of the pyramid: ";
    cin >> height;

    for (int i = 1; i <= height; i++) {
        // Print spaces
        for (int j = 1; j <= height - i; j++) {
            cout << "  ";
        }
        
        // Print increasing letters
        char ch = 'A';
        for (int k = 1; k <= i; k++) {
            cout << ch << " ";
            ch++;
        }
        
        // Print decreasing letters
        ch -= 2; // Go back two letters
        for (int l = 1; l < i; l++) {
            cout << ch << " ";
            ch--;
        }
        
        cout << endl;
    }
    return 0;
}
