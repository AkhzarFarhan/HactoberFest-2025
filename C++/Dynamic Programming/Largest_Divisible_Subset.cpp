#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        int maxLen = 1;
        int maxIdx = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIdx = i;
            }
        }

        vector<int> result;
        while (maxIdx != -1) {
            result.push_back(nums[maxIdx]);
            maxIdx = parent[maxIdx];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> result = sol.largestDivisibleSubset(nums);

    cout << "Largest Divisible Subset: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
