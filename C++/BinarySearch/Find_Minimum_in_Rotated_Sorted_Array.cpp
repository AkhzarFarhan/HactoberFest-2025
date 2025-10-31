/*
* C++ Solution for "Find Minimum in Rotated Sorted Array" (LeetCode 153)
*
* Problem: Given a sorted array of unique elements that has been
* rotated, find the minimum element in the array.
*
* This solution uses a modified binary search.
* Time complexity: O(log n).
*
* Contributor: Priyanka Anand
* Submitted for Hacktoberfest 2025
*/

#include <iostream>
#include <vector>
#include <algorithm> // For std::min

class Solution {
public:
    int findMin(const std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        // If the array is not rotated at all
        if (nums[left] <= nums[right]) {
            return nums[left];
        }

        // Binary search for the pivot point
        while (left < right) {
            int mid = left + (right - left) / 2;

            // The pivot is the only element where
            // the next element is smaller.
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }

            // If the mid element is greater than the right element,
            // the smallest element must be in the right part.
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } 
            // If the mid element is smaller than the right element,
            // the smallest element must be in the left part (including mid).
            else {
                right = mid;
            }
        }

        // At the end, left will point to the smallest element
        return nums[left];
    }
};

// Main function to test the implementation
int main() {
    Solution sol;

    std::vector<int> nums1 = {3, 4, 5, 1, 2};
    std::cout << "Test Case 1 (Expected 1): " << sol.findMin(nums1) << std::endl;

    std::vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    std::cout << "Test Case 2 (Expected 0): " << sol.findMin(nums2) << std::endl;

    std::vector<int> nums3 = {11, 13, 15, 17};
    std::cout << "Test Case 3 (Expected 11): " << sol.findMin(nums3) << std::endl;

    return 0;
}