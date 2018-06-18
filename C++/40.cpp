#include "mod.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>m_set;
        vector<bool>used(candidates.size(), false);
        vector<int>cur;
        std::sort(candidates.begin(), candidates.end());
        
        dfs(candidates, used, cur, target, 0, m_set);
        vector<vector<int>>ret(m_set.begin(), m_set.end());
        return ret;
    }
private:
    void dfs(const vector<int>& candidates, vector<bool>& used, vector<int>& cur, int target, int level, set<vector<int>>& m_set){
        if(target<0)return;
        if(target==0){
            m_set.insert(cur);
            return;
        }
        for(int i=level; i<candidates.size(); ++i){
            if(used[i]==true)continue;
            cur.push_back(candidates[i]);
            used[i]=true;
            dfs(candidates, used, cur, target-candidates[i], i, m_set);
            cur.pop_back();
            used[i]=false;
        }
        
    }
};