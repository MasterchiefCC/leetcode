#include "mod.h"
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>>ret;
        if(nums1.empty()||nums2.empty()||k==0)return ret;
        
        
        auto cmp=[&nums1, &nums2](const pair<int, int>& lhs, const pair<int, int>& rhs){
                return nums1[lhs.first]+nums2[lhs.second]>nums1[rhs.first]+nums2[rhs.second];
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>m_pq(cmp);
        m_pq.push({0,0});
        
        while(k--&&!m_pq.empty()){
            pair<int, int>idx_pair=m_pq.top(); m_pq.pop();
            ret.push_back({nums1[idx_pair.first], nums2[idx_pair.second]});
            
            if(idx_pair.first+1<nums1.size())
                m_pq.push({idx_pair.first+1, idx_pair.second});
            
            if(idx_pair.first==0&&idx_pair.second+1<nums2.size())
                m_pq.push({idx_pair.first, idx_pair.second+1});
        }
        return ret;
    }
};