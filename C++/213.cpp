#include "mod.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        return max(dp(nums, 0, nums.size()-1), dp(nums, 1, nums.size()));
    }
private:
    inline int dp(const vector<int>& nums,const int& start,const int& end){
        int profit=0, rest=0;
        for(int i=start; i<end; ++i){
            int pre_profit=profit, pre_rest=rest;
            rest=max(pre_profit, pre_rest);
            profit=pre_rest+nums[i];
        }
        return max(profit, rest);
    }
};