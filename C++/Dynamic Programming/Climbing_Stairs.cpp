/*
* C++ Solution for "Climbing Stairs" (LeetCode 70)
*
* Problem: You are climbing a staircase. It takes n steps
* to reach the top. Each time you can either climb 1 or 2 steps.
* In how many distinct ways can you climb to the top?
*
* This is a classic Dynamic Programming problem.
* The number of ways to reach step 'n' is:
* ways(n) = ways(n-1) + ways(n-2)
* This is the Fibonacci sequence.
*
* Contributor: Priyanka Anand
* Submitted for Hacktoberfest 2025
*/

#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }

        // We only need to store the last two steps
        int one_step_before = 1; // ways(1)
        int two_steps_before = 1; // ways(0)
        int all_ways = 0;

        for (int i = 2; i <= n; ++i) {
            all_ways = one_step_before + two_steps_before;

            // Update the previous steps for the next iteration
            two_steps_before = one_step_before;
            one_step_before = all_ways;
        }

        return all_ways;
    }
};

// Main function to test the implementation
int main() {
    Solution sol;

    int n1 = 2;
    // 1. 1 step + 1 step
    // 2. 2 steps
    std::cout << "Test Case 1 (n=2, Expected 2): " << sol.climbStairs(n1) << std::endl;

    int n2 = 3;
    // 1. 1 + 1 + 1
    // 2. 1 + 2
    // 3. 2 + 1
    std::cout << "Test Case 2 (n=3, Expected 3): " << sol.climbStairs(n2) << std::endl;

    int n3 = 5;
    // Expected: 8
    std::cout << "Test Case 3 (n=5, Expected 8): " << sol.climbStairs(n3) << std::endl;

    return 0;
}