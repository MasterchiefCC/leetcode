#include "mod.h"

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()<=0)return 0;

        vector<int>counter(10001, 0);
        for(int i=0; i<nums.size(); ++i)
            ++counter[nums[i]];
        
        vector<int>dp(10002, 0);
        dp[1]=counter[1]*1;
        int i=2;
        for(int i=2; i<10001; ++i)
            dp[i]=max(dp[i-1], dp[i-2]+counter[i]*i);
        return dp[10000];
    }
};