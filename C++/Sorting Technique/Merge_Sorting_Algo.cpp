// Merge Sort uses the Divide and Conquer Paradigm
/*
    STEPS :
    1)  Divide : we will break our problem statement into small problem and continue this process until single element left
    2)  Merge or Conquer : combines small-small problem and form one bigger solution by taking into account of our motive like (sorting or finding inversions etc. )
*/

// TC:  Best case = Average case = Worst case = O(nlogn)
// SC:  space complexity of merge sort is O(n)

#include <bits/stdc++.h>

using namespace std ;


// #define int long long
#define fr first
#define sc second
#define pb push_back
#define mp make_pair

void Merge(int *arr, int start, int mid, int end)
{
    int x = mid - start + 1;
    int y = end - mid;
    int a[x], b[y];
    for (int i = 0; i < x; i++)
        a[i] = arr[start + i];
    for (int i = 0; i < y; i++)
        b[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = start;
    while (i < x && j < y)
    {
        if (a[i] >= b[j])
        {
            arr[k++] = b[j++];
        }
        else
        {
            arr[k++] = a[i++];
        }
    }
    while (i < x)
        arr[k++] = a[i++];
    while (j < y)
        arr[k++] = b[j++];
}

void Mergesort(int *arr, int start, int end)
{
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    Mergesort(arr, start, mid);
    Mergesort(arr, mid + 1, end);
    Merge(arr, start, mid, end);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);

    printf("Before Sorting Array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    Mergesort(arr, 0, n - 1);

    printf("After Merge Sort Array is : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

// INPUT FORMAT :
// Insert N (number of element you want to sort)
// then Provide N numbers
