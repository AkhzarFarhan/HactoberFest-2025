// Link : https://leetcode.com/explore/learn/card/fun-with-arrays/526/deleting-items-from-an-array/3247/
#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0) return 0;
        
        
        int left = 0, right = nums.size()-1;
        while(left<right){
            if(nums[right]==val) right--;
            else if(nums[left]==val){
                swap(nums[left],nums[right]);
                left++,right--;
            }else left++;
        }
        int ans = 0;       
        for(int x : nums)
            if(x==val) break;
            else ans++;
        return ans;
    }
