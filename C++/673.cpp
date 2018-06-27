#include "mod.h"
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty())return 0;
        vector<pair<int, int>>dp(nums.size(), {1,1});
        for(int i=0; i<nums.size(); ++i){
            for(int j=i-1; j>=0; --j){
                if(nums[i]>nums[j]){
                    if(dp[i].first==dp[j].first+1)dp[i].second+=dp[j].second;
                    else if(dp[i].first<dp[j].first+1){
                        dp[i].first=dp[j].first+1;
                        dp[i].second=dp[j].second;
                    }
                }
            }
        }
        
        sort(dp.begin(), dp.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs){
                                    if(lhs.first==rhs.first)return lhs.second>rhs.second;
                                    return lhs.first>rhs.first;
                                    });
        int ret=0;
        int max_len=dp[0].first;
        int i=0;
        while(i<dp.size()&& dp[i].first==max_len)ret+=dp[i++].second;
        return ret;
            
    }
};

int main(){
    Solution test;
    vector <int>in={1,2,4,3,5,4,7,2};
    cout<<test.findNumberOfLIS(in);

}