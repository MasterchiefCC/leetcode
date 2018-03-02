class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		vector<int>curr(2001, 0);
		curr[nums[0]+1000]=1;
		curr[-nums[0]+1000]+=1;
		for (int i = 1; i < nums.size(); ++i) {
			vector<int>next(2001, 0);
			for (int sum = -1000; sum <= 1000; ++sum) {
				if (curr[sum + 1000] > 0) {
					next[sum + nums[i] + 1000] += curr[sum + 1000];
					next[sum - nums[i] + 1000] += curr[sum + 1000];
				}
			}
			curr=next;
		}
		return S > 1000 ? 0 : curr[S + 1000];
	}
};