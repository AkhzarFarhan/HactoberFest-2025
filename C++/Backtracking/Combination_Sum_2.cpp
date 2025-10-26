/*
Combination Sum II:

Given a collection of integers "candidates" (which may contain duplicates)
and a target integer "target", find all unique combinations of "candidates"
where the chosen numbers sum to target.

Each number in candidates may be used **only once** in each combination.

Use backtracking to explore all possible combinations while skipping duplicates.

Constraints:
- All numbers (including target) are positive integers.
- The solution set must not contain duplicate combinations.

Example:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[1, 1, 6]
[1, 2, 5]
[1, 7]
[2, 6]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive utility function
void combinationSum2Util(int start, vector<int> &candidates, int target,
                         vector<int> &current, vector<vector<int>> &ans)
{
    // Base case: target achieved
    if (target == 0)
    {
        ans.push_back(current);
        return;
    }

    for (int i = start; i < candidates.size(); i++)
    {
        // Skip duplicates
        if (i > start && candidates[i] == candidates[i - 1])
            continue;

        // Stop if element exceeds remaining target
        if (candidates[i] > target)
            break;

        // Include current element
        current.push_back(candidates[i]);
        combinationSum2Util(i + 1, candidates, target - candidates[i], current, ans);
        current.pop_back(); // backtrack
    }
}

// Main function
void combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
    vector<vector<int>> ans;
    vector<int> current;

    combinationSum2Util(0, candidates, target, current, ans);

    cout << "All unique combinations that sum to " << target << ":\n";
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
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    combinationSum2(candidates, target);
    return 0;
}
