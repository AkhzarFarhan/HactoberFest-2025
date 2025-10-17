#include <bits/stdc++.h>
using namespace std;

// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) { return s + (e - s) / 2; }

// Function to get the sum of values in the given range of the array.
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si) {
    // If segment of this node is a part of the given range
    if (qs <= ss && qe >= se) return st[si];

    // If segment of this node is outside the given range
    if (se < qs || ss > qe) return 0;

    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2 * si + 1) +
           getSumUtil(st, mid + 1, se, qs, qe, 2 * si + 2);
}

// Function to update the value in the segment tree.
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si) {
    // If the input index is out of range
    if (i < ss || i > se) return;

    // Update the value of the node and its children
    st[si] += diff;
    if (se != ss) {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2 * si + 1);
        updateValueUtil(st, mid + 1, se, i, diff, 2 * si + 2);
    }
}

// Update a value in the input array and segment tree
void updateValue(int arr[], int *st, int n, int i, int new_val) {
    if (i < 0 || i >= n) {
        cout << "Invalid Input" << endl;
        return;
    }
    int diff = new_val - arr[i];
    arr[i] = new_val;
    updateValueUtil(st, 0, n - 1, i, diff, 0);
}

// Return sum of elements in range from index qs to qe
int getSum(int *st, int n, int qs, int qe) {
    if (qs < 0 || qe >= n || qs > qe) {
        cout << "Invalid Input" << endl;
        return -1;
    }
    return getSumUtil(st, 0, n - 1, qs, qe, 0);
}

// Recursive function that constructs Segment Tree for array[ss..se]
int constructSTUtil(int arr[], int ss, int se, int *st, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, 2 * si + 1) +
             constructSTUtil(arr, mid + 1, se, st, 2 * si + 2);
    return st[si];
}

// Construct segment tree from given array
int *constructST(int arr[], int n) {
    if (n <= 0) return nullptr; // Handle empty array case
    int x = (int)(ceil(log2(n))); // Height of segment tree
    int max_size = 2 * (int)pow(2, x) - 1; // Maximum size of segment tree
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}

// Driver program to test the above functions
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Build segment tree from given array
    int *st = constructST(arr, n);

    // Print sum of values in array from index 1 to 3
    cout << "Sum of values in given ra
