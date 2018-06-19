#include "mod.h"
class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(nums.begin(), nums.end());
        vector<int>cur, ret;
		dfs(nums, cur, ret, 0);
		return ret;
	}
private:
	void dfs(const vector<int>& nums, vector<int>& cur, vector<int>& ret, int level) {
		for (int i = level; i<nums.size(); ++i) {
			bool lock = false;
			if (cur.empty()||cur.back()%nums[i]==0||nums[i]%cur.back()==0)lock = true;
			if (!lock)continue;
			cur.push_back(nums[i]);
			dfs(nums, cur, ret, i + 1);
            if(cur.size()>ret.size())ret=cur;
            if(ret.size()>=nums.size()-1)return;
			cur.pop_back();
		}
	}
};