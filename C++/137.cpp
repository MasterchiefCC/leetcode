#include "mod.h"
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret=nums[nums.size()-1];
        for(int i=0; i<nums.size()-2; i+=3){
            if(nums[i]!=nums[i+1])return nums[i];
            if(nums[i]!=nums[i+2])return nums[i+2];
        }
        
        return ret;
    }
};