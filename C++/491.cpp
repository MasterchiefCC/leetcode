#include "mod.h"

class Solution {
    void helper(const vector<int>& nums, vector<int>&cur_arr, int level, set<vector<int>> &m_set){
        if(cur_arr.size()>=2)m_set.insert(cur_arr);
        for(int i=level; i<nums.size(); ++i){
            if(cur_arr.empty()||cur_arr.back()<=nums[i]){
                cur_arr.push_back(nums[i]);
                helper(nums, cur_arr, i+1, m_set);
                cur_arr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>cur_arr;
        set<vector<int>> m_set;
        helper(nums, cur_arr, 0, m_set);
        vector<vector<int>>ret;
        for(auto it=m_set.begin(); it!=m_set.end(); ++it){
            ret.push_back(*it);
        }
        return ret;
    }
};