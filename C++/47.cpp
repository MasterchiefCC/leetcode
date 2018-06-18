#include "mod.h"
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>m_set;
        vector<int>cur;
        vector<bool>used(nums.size(), false);
        dfs(nums, m_set, cur, used);
        return vector<vector<int>>(m_set.begin(), m_set.end());
    }
private:
    void dfs(const vector<int>& nums,set<vector<int>>& m_set, vector<int>& cur, vector<bool> &used){
        if(cur.size()==nums.size()){
            m_set.insert(cur);
            return;
        }
        for(int i=0; i<nums.size(); ++i){
            if(used[i])continue;
            used[i]=true;
            cur.push_back(nums[i]);
            dfs(nums, m_set, cur, used);
            used[i]=false;
            cur.pop_back();
        }
    }
};