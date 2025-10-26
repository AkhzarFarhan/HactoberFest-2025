/*Combination Sum III:

Find all possible combinations of "k" numbers that add up to a number "n",
given that only numbers from 1 to 9 can be used, and each number may be used at most once.

Use backtracking to explore all possible number combinations.

Constraints:
- 1 ≤ k ≤ 9
- 1 ≤ n ≤ 60
- Each combination should contain unique numbers between 1 and 9.

Example:
Input: k = 3, n = 7
Output:
[1, 2, 4]

Input: k = 3, n = 9
Output:
[1, 2, 6]
[1, 3, 5]
[2, 3, 4]
*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive utility function
void combinationSum3Util(int start, int k, int n,
                         vector<int> &current, vector<vector<int>> &ans)
{
    // Base case: if valid combination found
    if (current.size() == k && n == 0)
    {
        ans.push_back(current);
        return;
    }

    // Stop if number exceeds 9 or combination too large
    for (int i = start; i <= 9; i++)
    {
        if (i > n) // no need to continue
            break;

        current.push_back(i);
        combinationSum3Util(i + 1, k, n - i, current, ans);
        current.pop_back(); // backtrack
    }
}

// Main function
void combinationSum3(int k, int n)
{
    vector<vector<int>> ans;
    vector<int> current;
    combinationSum3Util(1, k, n, current, ans);

    cout << "All combinations of " << k << " numbers that sum to " << n << ":\n";
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
    int k = 3, n = 9;
    combinationSum3(k, n);
    return 0;
}
