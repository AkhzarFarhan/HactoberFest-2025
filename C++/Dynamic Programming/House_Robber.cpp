/*
* C++ Solution for "House Robber" (LeetCode 198)
*
* Problem: You are a professional robber planning to rob houses
* along a street. Each house has a certain amount of money.
* You cannot rob two adjacent houses.
* Find the maximum amount of money you can rob.
*
* This is a classic Dynamic Programming problem.
* rob(i) = max( rob(i-1) , rob(i-2) + nums[i] )
* (Max of skipping the current house vs. robbing it)
*
* Contributor: Priyanka Anand
* Submitted for Hacktoberfest 2025
*/

#include <iostream>
#include <vector>
#include <algorithm> // For std::max

class Solution {
public:
    int rob(const std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        // We only need to store the max profit from robbing
        // the previous two houses.
        int rob_prev_prev = 0;     // Represents rob(i-2)
        int rob_prev = 0;          // Represents rob(i-1)

        // Iterate through each house
        for (int current_house_money : nums) {
            // Find the max profit up to this point
            // max( skipping this house , robbing this house )
            int current_max = std::max(rob_prev, rob_prev_prev + current_house_money);

            // Shift the values for the next iteration
            rob_prev_prev = rob_prev;
            rob_prev = current_max;
        }

        // The final answer is the max profit after
        // considering all houses
        return rob_prev;
    }
};

// Main function to test the implementation
int main() {
    Solution sol;

    std::vector<int> nums1 = {1, 2, 3, 1};
    // Rob 1 + 3 = 4
    std::cout << "Test Case 1 (Expected 4): " << sol.rob(nums1) << std::endl;

    std::vector<int> nums2 = {2, 7, 9, 3, 1};
    // Rob 2 + 9 + 1 = 12
    std::cout << "Test Case 2 (Expected 12): " << sol.rob(nums2) << std::endl;

    return 0;
}