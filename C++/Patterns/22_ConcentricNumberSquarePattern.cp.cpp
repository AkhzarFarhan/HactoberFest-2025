// 22. Concentric Number Square Pattern
#include <iostream>
#include <algorithm> // For min()
using namespace std;

int main() {
    int n;
    cout << "Enter the size (n) for the (2n-1) square: ";
    cin >> n;

    int size = 2 * n - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Find the minimum distance from any edge
            int dist_top = i;
            int dist_bottom = size - 1 - i;
            int dist_left = j;
            int dist_right = size - 1 - j;
            
            int min_dist = min({dist_top, dist_bottom, dist_left, dist_right});
            
            // The number to print is n - min_dist
            cout << (n - min_dist) << " ";
        }
        cout << endl;
    }
    return 0;
}