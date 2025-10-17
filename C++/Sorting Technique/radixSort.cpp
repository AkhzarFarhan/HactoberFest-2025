#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to get the maximum value in the array
int getMax(const vector<int>& arr) {
    int max_val = arr[0];
    for (int num : arr) {
        if (num > max_val)
            max_val = num;
    }
    return max_val;
}

// Counting Sort function to sort array according to the digit represented by exp (10^exp)
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // Output array
    int count[10] = {0};   // Count array to store occurrences of digits

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that it now contains the actual position of this digit in the output array
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr now contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main Radix Sort function
void radixSort(vector<int>& arr) {
    // Find the maximum number to determine the number of digits
    int max_val = getMax(arr);

    // Do counting sort for every digit. exp is 10^i where i is the current digit number
    for (int exp = 1; max_val / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

// Driver code to test the radix sort function
int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    
    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    // Perform radix sort
    radixSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
