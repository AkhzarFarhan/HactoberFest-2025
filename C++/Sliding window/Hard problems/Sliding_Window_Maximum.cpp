/*
* C++ Solution for LeetCode 239: "Sliding Window Maximum"
*
* Problem: You are given an array of integers nums, 
* there is a sliding window of size k which is moving 
* from the very left of the array to the very right. 
* You can only see the k numbers in the window. 
* Each time the sliding window moves right by one position.
* Return the max sliding window.
*
* Contributor: Priyanka Anand
* Submitted for Hacktoberfest 2025
*/

#include <iostream>
#include <vector>
#include <deque>
#include <string> // for printing

class Solution {
public:
    std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
        std::vector<int> result;
        if (nums.empty() || k == 0) {
            return result;
        }

        // Deque will store indices of useful elements
        // It will be in decreasing order of values
        std::deque<int> dq;

        for (int i = 0; i < nums.size(); ++i) {
            // 1. Remove elements from the front that are out of
            // the current window [i-k+1, i]
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // 2. Remove elements from the back that are smaller
            // than the current element nums[i]
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // 3. Add the current element's index to the back
            dq.push_back(i);

            // 4. The front of the deque is the largest element
            // for the current window. Add it to results once
            // the window has at least k elements.
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};

// Helper function to print a vector
void printVector(const std::string& title, const std::vector<int>& vec) {
    std::cout << title;
    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

// Main function to test the solution
int main() {
    Solution sol;

    std::vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    std::vector<int> result1 = sol.maxSlidingWindow(nums1, k1);
    // Expected: 3 3 5 5 6 7
    printVector("Test Case 1 (Expected 3 3 5 5 6 7): ", result1);

    std::vector<int> nums2 = {1};
    int k2 = 1;
    std::vector<int> result2 = sol.maxSlidingWindow(nums2, k2);
    // Expected: 1
    printVector("Test Case 2 (Expected 1): ", result2);

    return 0;
}