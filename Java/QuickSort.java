import java.util.Arrays;

public class QuickSort {

    /* 
     * Quicksort:
     * 
     * Working: Quicksort is a divide-and-conquer algorithm that selects a pivot element, partitions the Array into 
     *          elements less than and greater than the pivot, and then recursively sorts the subArrays.
     * 
     * Stability: Quicksort is not stable.
     * 
     * Time Complexity(Best): O(n log n) - Occurs when the pivot consistently divides the Array into nearly equal halves.
     * 
     * Time Complexity(Worst): O(n^2) - Occurs when the pivot selection consistently leads to unbalanced partitions.
     * 
     * Space Complexity: O(1) - Quicksort sorts the Array in-place.
     * 
     * Unique Feature: Quicksort is an efficient divide-and-conquer algorithm with good average-case performance. It relies 
     *                 heavily on the choice of the pivot element, which can affect its worst-case behavior.
     * 
    */

    public static void quickSort(int[] A, int low, int high) {
        if (low >= high) {
            return;
        }

        int start = low;
        int end = high;
        int mid = start + (end - start) / 2;

        int pivot = A[mid];

        while (start <= end) {
            while (A[start] < pivot) {
                start++;
            }

            while (A[end] > pivot) {
                end--;
            }

            if (start <= end) {
                int temp = A[start];
                A[start] = A[end];
                A[end] = temp;
                start++;
                end--;
            }
        }

        quickSort(A, low, end);
        quickSort(A, start, high);
    }

    public static void main(String[] args) {
        int[] A = {23, 12, 1, 5, 6, 9, 13, 19, 7 };
        System.out.println("Original Array: " + Arrays.toString(A));

        quickSort(A, 0, A.length -1);

        System.out.println("Array After Merge Sort: " + Arrays.toString(A));
    }
}
