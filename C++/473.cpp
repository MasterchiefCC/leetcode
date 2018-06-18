#include "mod.h"
class Solution {
public:
	bool makesquare(vector<int>& nums) {
		if (nums.size()<4)return false;
		int sum = std::accumulate(nums.begin(), nums.end(), 0);
		if (sum % 4 != 0)return false;
		sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        
		vector<int>buffer(4, 0);
		return dfs(nums, buffer, 0, sum / 4);
	}
private:
	bool dfs(const vector<int>& nums, vector<int>& buffer, int pos, const int& target) {
		
		if (pos >= nums.size()) { 
			for (int i = 0; i < buffer.size(); ++i)if (buffer[i] != target)return false; 
			return true;
		}
		
		for (int i = 0; i<buffer.size(); ++i) {
			if (nums[pos] + buffer[i]>target)continue;
			buffer[i] += nums[pos];
			if (dfs(nums, buffer, pos + 1, target))return true;
			buffer[i] -= nums[pos];
		}
		return false;
	}
};