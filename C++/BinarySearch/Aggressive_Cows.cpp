/*
* C++ Solution for "Aggressive Cows" (SPOJ - AGGRCOW)
*
* Problem: Farmer John has N stalls, C cows. He wants to assign
* the cows to stalls such that the minimum distance between any
* two of them is as large as possible. What is the largest
* minimum distance?
*
* This is a classic "Binary Search on the Answer" problem.
* We binary search for the largest possible minimum distance.
*
* Contributor: Priyanka Anand
* Submitted for Hacktoberfest 2025
*/

#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

/**
 * @brief Checks if it's possible to place 'cows' in 'stalls'
 * with at least 'min_dist' distance between them.
 * @param stalls A sorted vector of stall positions.
 * @param cows The number of cows to place.
 * @param min_dist The minimum distance to check.
 * @return true if placement is possible, false otherwise.
 */
bool canPlaceCows(const std::vector<int>& stalls, int cows, int min_dist) {
    int cowsPlaced = 1; // Place the first cow in the first stall
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); ++i) {
        // Check if we can place the next cow at stall i
        if (stalls[i] - lastPos >= min_dist) {
            cowsPlaced++;
            lastPos = stalls[i];
        }
        if (cowsPlaced == cows) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Finds the largest minimum distance between any two cows.
 * @param stalls A vector of stall positions.
 * @param cows The number of cows.
 * @return The largest minimum distance.
 */
int aggressiveCows(std::vector<int>& stalls, int cows) {
    // Sort the stalls to apply binary search
    std::sort(stalls.begin(), stalls.end());

    int n = stalls.size();
    int low = 0; // Minimum possible distance
    int high = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int ans = 0;

    // Binary search for the answer
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, cows, mid)) {
            // If we can place cows with distance 'mid',
            // this is a potential answer. Try for a larger distance.
            ans = mid;
            low = mid + 1;
        } else {
            // If we can't, we need to try a smaller distance.
            high = mid - 1;
        }
    }
    return ans;
}

// Main function to test the implementation
int main() {
    std::vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;

    // Stalls sorted: {1, 2, 4, 8, 9}
    // Possible to place 3 cows with dist 3 (at 1, 4, 8 or 1, 4, 9)
    // Not possible with dist 4.

    int result = aggressiveCows(stalls, cows);

    std::cout << "Test Case (Expected 3): " << result << std::endl;

    return 0;
}