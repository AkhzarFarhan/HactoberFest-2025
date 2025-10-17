#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxNum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxNum)
            maxNum = arr[i];
    }

    cout << "The maximum number in the array is: " << maxNum << endl;

    return 0;
}
