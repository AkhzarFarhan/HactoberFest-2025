/*
Combination Sum I:

Given an array of distinct integers "candidates" and a target integer "target",
find all unique combinations of "candidates" where the chosen numbers sum to target.

The same number may be chosen an unlimited number of times.

Use backtracking to explore all combinations by adding elements repeatedly
until the sum equals the target or exceeds it.

Constraints:
- All numbers (including target) are positive integers.
- Elements in each combination must be in non-decreasing order.

Example:
Input: candidates = [2,3,6,7], target = 7
Output:
[2, 2, 3]
[7]
*/
#include <iostream>
#include <vector>
using namespace std;

// Recursive utility function to find combinations
void combinationSumUtil(int idx, vector<int> &candidates, int target,
                        vector<int> &current, vector<vector<int>> &ans)
{
    // Base case: if target is achieved
    if (target == 0)
    {
        ans.push_back(current);
        return;
    }

    // If we have processed all elements or target < 0
    if (idx == candidates.size())
        return;

    // Include current element (if it doesn't exceed target)
    if (candidates[idx] <= target)
    {
        current.push_back(candidates[idx]);
        combinationSumUtil(idx, candidates, target - candidates[idx], current, ans);
        current.pop_back(); // backtrack
    }

    // Exclude current element and move forward
    combinationSumUtil(idx + 1, candidates, target, current, ans);
}

// Main function to print all combinations
void combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> current;
    combinationSumUtil(0, candidates, target, current, ans);

    cout << "All possible combinations that sum to " << target << ":\n";
    for (auto &comb : ans)
    {
        cout << "[ ";
        for (int num : comb)
            cout << num << " ";
        cout << "]\n";
    }
}

// Driver Code
int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    combinationSum(candidates, target);
    return 0;
}
