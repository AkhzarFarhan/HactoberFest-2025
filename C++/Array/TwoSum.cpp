#include <bits/stdc++.h>
using namespace std;

/**
 * Author:veeru yadav
 * GitHub: https://github.com/VeeruYadav45
 */

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> v;
        for (int i = 0; i < nums.size(); i++)
            v[nums[i]] = i;

        for (int j = 0; j < nums.size(); j++)
        {
            int c = target - nums[j];
            if (v.count(c) && v[c] != j)
                return {j, v[c]};
        }
        return {};
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);
    cout << "Indices: ";
    for (int idx : result)
        cout << idx << " ";
    cout << endl;

    return 0;
}
