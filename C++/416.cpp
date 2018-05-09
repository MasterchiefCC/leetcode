#include "mod.h"

class Solution_bySet {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%2==1)return false;
        int target=sum/2;
        unordered_set<int>m_set;
        m_set.insert(0);
        for(const int num:nums){
            vector<int>temp;
            for(auto it=m_set.begin(); it!=m_set.end(); ++it){
                temp.push_back(*it+num);
            }
            for(int i=0; i<temp.size(); ++i)
                m_set.insert(temp[i]);
            if(m_set.find(target)!=m_set.end())return true;
        }
        return false;
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum%2==1)return false;
        int target=sum/2;
        vector<bool>dp(sum, false);
        dp[0]=true;
        for(const int &num: nums){
            for(int i=sum; i>=0; --i)
                if(dp[i])dp[i+num]=true;
            if(dp[target])return true;
        }
        return false;
    }
};
