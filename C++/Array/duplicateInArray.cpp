//find duplicate: 
// Link : https://leetcode.com/problems/contains-duplicate-ii/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int,int> m;
        unordered_map<int,int>::iterator it;
        
        
        for(int i=0; i<nums.size(); ++i) {
            it = m.find(nums[i]);
            if(it != m.end() and i - it->second <= k) return true;
            else m[nums[i]] = i;
        }
        return false;
    }
};
