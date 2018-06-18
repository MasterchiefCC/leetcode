#include "mod.h"

class Solution {
	void helper(const vector<int>& candidates, \
		vector<int> &cur_buffer, int cur_val, int cur_depth, \
		const int &target, vector<vector<int>> &ret) {
		if (cur_val>target)return;
		if (cur_val == target) {
			ret.push_back(cur_buffer);
			return;
		}
		for (int i = cur_depth; i<candidates.size(); ++i) {
			cur_buffer.push_back(candidates[i]);
			helper(candidates, cur_buffer, cur_val + candidates[i], i, target, ret);
			cur_buffer.pop_back();
		}
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>>ret;
		vector<int>cur_buffer;
		helper(candidates, cur_buffer, 0, 0, target, ret);
		return ret;
	}
};