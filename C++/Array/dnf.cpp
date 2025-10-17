// Dutch National Flag problem (sort array of 0,1,2) - C++
// In-place, single pass (three pointers), O(n) time, O(1) extra space.

#include <bits/stdc++.h>
using namespace std;

void dutchNationalFlagSort(vector<int>& a) {
    int low = 0;                 // boundary for 0s
    int mid = 0;                 // current element
    int high = (int)a.size() - 1; // boundary for 2s

    while (mid <= high) {
        if (a[mid] == 0) {
            swap(a[low], a[mid]);
            low++;
            mid++;
        } else if (a[mid] == 1) {
            mid++;
        } else { // a[mid] == 2
            swap(a[mid], a[high]);
            high--;
            // do not increment mid here because swapped element must be examined
        }
    }
}

int main() {
    vector<int> arr = {2, 0, 2, 1, 1, 0, 2, 0, 1};
    dutchNationalFlagSort(arr);
    for (int x : arr) cout << x << ' ';
    cout << '\n';
    return 0;
}
