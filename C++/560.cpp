#include"mod.h"
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int>m_map;
        m_map[0]=1;
        int sum=0, ret=0;
        for(int i=0; i<nums.size(); ++i){
            sum+=nums[i];
            ret+=m_map[sum-k];
            ++m_map[sum];
        }
        return ret;
    }
};